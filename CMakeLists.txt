cmake_minimum_required(VERSION 3.16)
project(bybit_c VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

find_package(CURL REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)

add_library(bybit
    src/buf.c
    src/json.c
    src/sign.c
    src/host.c
    src/client.c
    src/http.c
    src/catalog.c
    src/endpoints.c
    src/topics.c
    src/orderbook.c
    src/ws_transport.c
    src/ws.c
)
target_include_directories(bybit PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_definitions(bybit PRIVATE _POSIX_C_SOURCE=200809L)
target_link_libraries(bybit PUBLIC CURL::libcurl OpenSSL::SSL OpenSSL::Crypto Threads::Threads)

add_executable(bybit_example_ticker examples/ticker.c)
target_link_libraries(bybit_example_ticker PRIVATE bybit)

add_executable(bybit_example_ws examples/ws_public_trade.c)
target_link_libraries(bybit_example_ws PRIVATE bybit)
