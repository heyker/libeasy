# Set the project name
project (packet)
set(HEADERS
    http/easy_http_handler.h
    http/http_parser.h
    easy_simple_handler.h
    easy_tbnet.h
    easy_kfc_handler.h
)

set(SOURCES
    http/easy_http_handler.c
    http/http_parser.c
    easy_kfc_handler.c
)

# Add a library with the above sources
add_library(${PROJECT_NAME} STATIC
    ${HEADERS}
    ${SOURCES}
)

add_library(easy::packet ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC  ${PROJECT_SOURCE_DIR})