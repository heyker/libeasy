# Set the project name
project (io)

# Add a library with the above sources
add_library(${PROJECT_NAME} STATIC
    easy_socket.c
	easy_io.c
	easy_file.c
	ev.c
	easy_connection.c
	easy_summary.c
	easy_message.c
	easy_request.c
	easy_baseth_pool.c
	easy_log.c
	easy_ssl.c
	easy_event.c
	easy_client.c
)
add_library(easy::io ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC  ${PROJECT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME}
PUBLIC
	easy::include
	easy::util
	easy::thread
	easy::packet
)