#!/usr/bin/env python3
"""Generate the Bybit V5 endpoint catalog from a checkout of bybit-exchange/docs."""

import os
import re
import sys

DOCS_SHA = "d5a43d2d010c4468e3f7d992408eaff88a48068a"

ENDPOINT = re.compile(r"<APIEndpoint\s+([^>]+)/?>", re.I)
METHOD = re.compile(r'method="([^"]+)"')
URL = re.compile(r'url="([^"]+)"')
HTTP = re.compile(r"^(GET|POST|PUT|DELETE|PATCH)\s+(/v5/[^\s?]+)", re.M)
TITLE = re.compile(r"^title:\s*(.+)$", re.M)
IDENT = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")

PUBLIC_PREFIXES = ("/v5/market/", "/v5/announcements/")
PUBLIC_EXACT = {
    "/v5/system/status",
    "/v5/spot-lever-token/info",
    "/v5/spot-lever-token/reference",
    "/v5/spread/orderbook",
    "/v5/spread/tickers",
    "/v5/spread/recent-trade",
    "/v5/spread/instrument",
    "/v5/event/orderbook",
    "/v5/event/instruments-info",
}


def c_string(text):
    out = ['"']
    for ch in text:
        if ch == "\\":
            out.append("\\\\")
        elif ch == '"':
            out.append('\\"')
        elif ch == "\n":
            out.append("\\n")
        elif ch == "\r":
            continue
        elif ord(ch) < 32:
            out.append("\\x%02x" % ord(ch))
        else:
            out.append(ch)
    out.append('"')
    return "".join(out)


def c_comment(text):
    return text.replace("*/", "* /")


def required_params(text):
    parts = text.split("### Request Parameters", 1)
    if len(parts) < 2:
        return []
    table = parts[1].split("###", 1)[0]
    found = []
    for line in table.splitlines():
        if not line.startswith("|"):
            continue
        cols = [c.strip() for c in line.strip().strip("|").split("|")]
        if len(cols) < 2:
            continue
        name = re.sub(r"\[([^\]]+)\].*", r"\1", cols[0])
        name = re.sub(r"[`*]", "", name)
        name = re.sub(r"<[^>]+>", "", name).strip()
        if not name or name.lower() == "parameter" or set(name) <= set("-: "):
            continue
        if name.startswith(">"):
            continue
        flag = cols[1].lower()
        if "true" not in flag or "false" in flag:
            continue
        token = IDENT.match(name)
        if token and token.group(0) not in found:
            found.append(token.group(0))
    return found


def auth_required(path, text):
    if path.startswith(PUBLIC_PREFIXES) or path in PUBLIC_EXACT:
        return 0
    low = text.lower()
    if "does not require authentication" in low or "do not require authentication" in low:
        return 0
    if "not require authentication" in low or "no authentication" in low:
        return 0
    if "X-BAPI" in text or "api_key=" in text or "api_key =" in text:
        return 1
    return 0


def function_name(method, path):
    body = path[4:].strip("/")
    name = "bybit_" + body.replace("/", "_").replace("-", "_")
    if method != "GET":
        # Disambiguated later when the path is shared.
        return name
    return name


def collect(root):
    items = {}
    for dirpath, _, files in os.walk(root):
        for filename in files:
            if not filename.endswith((".mdx", ".md")):
                continue
            path = os.path.join(dirpath, filename)
            rel = os.path.relpath(path, root)
            if rel.startswith("abandon/") or "/abandon/" in rel:
                continue
            text = open(path, encoding="utf-8", errors="replace").read()
            found = []
            for tag in ENDPOINT.findall(text):
                method = METHOD.search(tag)
                url = URL.search(tag)
                if method and url:
                    found.append((method.group(1).upper(), url.group(1)))
            if not found:
                found = HTTP.findall(text)
            if not found:
                continue
            title_match = TITLE.search(text)
            title = title_match.group(1).strip().strip('"') if title_match else rel
            req = required_params(text)
            for method, url in found:
                key = (method, url)
                if key in items:
                    continue
                items[key] = {
                    "method": method,
                    "path": url,
                    "title": title,
                    "doc": rel,
                    "required": req,
                    "auth": auth_required(url, text),
                }
    return items


def assign_names(items):
    used = {}
    ordered = []
    for key in sorted(items, key=lambda k: (k[1], k[0])):
        item = items[key]
        base = function_name(item["method"], item["path"])
        name = base
        if name in used:
            name = base + "_" + item["method"].lower()
            other = used[base]
            if not other["name"].endswith("_" + other["method"].lower()):
                other["name"] = function_name(other["method"], other["path"]) + "_" + other["method"].lower()
        item["name"] = name
        used[name] = item
        used[base] = item
        ordered.append(item)
    # A second pass in case the first occupant was renamed after being stored.
    seen = {}
    for item in ordered:
        if item["name"] in seen and seen[item["name"]] is not item:
            item["name"] = function_name(item["method"], item["path"]) + "_" + item["method"].lower()
        seen[item["name"]] = item
    return ordered


def emit(ordered, include_dir, src_dir):
    header = os.path.join(include_dir, "bybit", "endpoints.h")
    source = os.path.join(src_dir, "endpoints.c")
    with open(header, "w", encoding="utf-8") as fh:
        fh.write("#ifndef BYBIT_ENDPOINTS_H\n#define BYBIT_ENDPOINTS_H\n\n")
        fh.write("#include \"bybit/types.h\"\n\n")
        fh.write("#ifdef __cplusplus\nextern \"C\" {\n#endif\n\n")
        fh.write("/* Generated from bybit-exchange/docs %s. Do not edit. */\n\n" % DOCS_SHA)
        fh.write("typedef struct bybit_endpoint {\n")
        fh.write("    const char *name;\n")
        fh.write("    const char *method;\n")
        fh.write("    const char *path;\n")
        fh.write("    const char *title;\n")
        fh.write("    const char *doc;\n")
        fh.write("    const char *required;\n")
        fh.write("    int auth_required;\n")
        fh.write("} bybit_endpoint;\n\n")
        fh.write("size_t bybit_endpoint_count(void);\n")
        fh.write("const bybit_endpoint *bybit_endpoint_at(size_t index);\n")
        fh.write("const bybit_endpoint *bybit_endpoint_find(const char *method, const char *path);\n")
        fh.write("bybit_err bybit_endpoint_invoke(bybit_client *client, const bybit_endpoint *endpoint,\n")
        fh.write("                                const bybit_kv *fields, size_t nfields, bybit_response **out);\n\n")
        for item in ordered:
            req = ", ".join(item["required"]) if item["required"] else "none"
            auth = "private" if item["auth"] else "public"
            fh.write("/* %s. %s %s. Auth: %s. Required: %s. */\n" % (
                c_comment(item["title"]), item["method"], item["path"], auth, req))
            fh.write("bybit_err %s(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);\n\n" % item["name"])
        fh.write("#ifdef __cplusplus\n}\n#endif\n\n#endif /* BYBIT_ENDPOINTS_H */\n")
    with open(source, "w", encoding="utf-8") as fh:
        fh.write("/* Generated from bybit-exchange/docs %s. Do not edit. */\n" % DOCS_SHA)
        fh.write('#include "bybit/endpoints.h"\n\n')
        fh.write("const bybit_endpoint bybit_endpoint_table[] = {\n")
        for index, item in enumerate(ordered):
            req = ", ".join(item["required"])
            fh.write("    { %s, %s, %s, %s, %s, %s, %d },\n" % (
                c_string(item["name"]),
                c_string(item["method"]),
                c_string(item["path"]),
                c_string(item["title"]),
                c_string(item["doc"]),
                c_string(req),
                item["auth"],
            ))
            item["index"] = index
        fh.write("};\n\n")
        fh.write("const size_t bybit_endpoint_table_count = sizeof bybit_endpoint_table / sizeof bybit_endpoint_table[0];\n\n")
        for item in ordered:
            fh.write("bybit_err %s(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)\n" % item["name"])
            fh.write("{\n    return bybit_endpoint_invoke(client, &bybit_endpoint_table[%d], fields, nfields, out);\n}\n\n" % item["index"])


def main():
    if len(sys.argv) != 4:
        sys.stderr.write("usage: gen_endpoints.py DOCS_V5_DIR INCLUDE_DIR SRC_DIR\n")
        return 2
    items = collect(sys.argv[1])
    ordered = assign_names(items)
    names = [item["name"] for item in ordered]
    if len(names) != len(set(names)):
        sys.stderr.write("duplicate function names\n")
        return 1
    for name in names:
        if not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", name) or len(name) > 63:
            sys.stderr.write("bad name %s\n" % name)
            return 1
    os.makedirs(os.path.join(sys.argv[2], "bybit"), exist_ok=True)
    os.makedirs(sys.argv[3], exist_ok=True)
    emit(ordered, sys.argv[2], sys.argv[3])
    public = sum(1 for item in ordered if not item["auth"])
    print("endpoints %d public %d private %d" % (len(ordered), public, len(ordered) - public))
    return 0


if __name__ == "__main__":
    sys.exit(main())
