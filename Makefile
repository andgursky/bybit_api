# bybit-c — C11 client for the Bybit V5 API.
CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -Wshadow -Wstrict-prototypes -Wmissing-prototypes -O2
CPPFLAGS += -Iinclude -D_POSIX_C_SOURCE=200809L
CPPFLAGS += $(shell pkg-config --cflags libcurl openssl)
LDLIBS += $(shell pkg-config --libs libcurl openssl) -pthread

SRCS := src/buf.c src/json.c src/sign.c src/host.c src/client.c src/http.c \
        src/catalog.c src/endpoints.c src/topics.c src/orderbook.c src/ws_transport.c src/ws.c
OBJS := $(SRCS:src/%.c=build/%.o)

.PHONY: all test clean

all: build/libbybit.a

build:
	mkdir -p build

build/%.o: src/%.c | build
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

build/libbybit.a: $(OBJS)
	ar rcs $@ $(OBJS)

build/test_unit: tests/test_unit.c $(SRCS) | build
	$(CC) $(CPPFLAGS) $(CFLAGS) -g -O1 -fsanitize=address,undefined -o $@ tests/test_unit.c $(SRCS) $(LDLIBS) -fsanitize=address,undefined

build/test_live: tests/test_live.c build/libbybit.a
	$(CC) $(CPPFLAGS) $(CFLAGS) -g -o $@ tests/test_live.c build/libbybit.a $(LDLIBS)

build/example_ticker: examples/ticker.c build/libbybit.a
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ examples/ticker.c build/libbybit.a $(LDLIBS)

build/example_ws_trade: examples/ws_public_trade.c build/libbybit.a
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ examples/ws_public_trade.c build/libbybit.a $(LDLIBS)

test: build/test_unit build/test_live
	ASAN_OPTIONS=detect_leaks=1 ./build/test_unit
	./build/test_live

clean:
	rm -rf build
