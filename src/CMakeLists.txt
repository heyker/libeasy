project(easy)

include_directories(
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/io
	${PROJECT_SOURCE_DIR}/packet
	${PROJECT_SOURCE_DIR}/packet/http
)

add_subdirectory(include)
add_subdirectory(util)
add_subdirectory(thread)
add_subdirectory(memory)
#add_subdirectory(io)

# Add a full library about all
set(HEADERS
    packet/http/easy_http_handler.h
    packet/http/http_parser.h
    packet/easy_simple_handler.h
    packet/easy_tbnet.h
    packet/easy_kfc_handler.h
    io/easy_io.h
	io/easy_file.h
	io/easy_summary.h
	io/easy_message.h
	io/easy_request.h
	io/easy_socket.h
	io/easy_client.h
	io/easy_io_struct.h
	io/easy_baseth_pool.h
	io/easy_log.h
	io/easy_ssl.h
	io/easy_event.h
	io/ev.h
)

set(SOURCES
    packet/http/easy_http_handler.c
    packet/http/http_parser.c
    packet/easy_kfc_handler.c
    io/easy_socket.c
	io/easy_io.c
	io/easy_file.c
	io/ev.c
	io/easy_connection.c
	io/easy_summary.c
	io/easy_message.c
	io/easy_request.c
	io/easy_baseth_pool.c
	io/easy_log.c
	io/easy_ssl.c
	io/easy_event.c
    io/easy_client.c
)
add_library(${PROJECT_NAME} STATIC
    ${HEADERS}
    ${SOURCES}
)
#add_library(${PROJECT_NAME}_static STATIC
#    ${HEADERS}
#    ${SOURCES}
#)

#SET_TARGET_PROPERTIES(${PROJECT_NAME}_static PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
#SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES CLEAN_DIRECT_OUTPUT 1)
#SET_TARGET_PROPERTIES(${PROJECT_NAME}_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

add_library(easy::all ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
${PROJECT_SOURCE_DIR}/include
${PROJECT_SOURCE_DIR}/io
${PROJECT_SOURCE_DIR}/packet
${PROJECT_SOURCE_DIR}/packet/http
)

target_link_libraries(${PROJECT_NAME}
PUBLIC
	easy::include
	easy::util
    easy::thread
    easy::memory
)

