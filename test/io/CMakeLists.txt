project(io_test)

set(TEST_SOURCE
	io_test.c
    easy_io_test.c
    easy_baseth_pool_test.c
    easy_client_test.c
    easy_connection_test.c
    easy_log_test.c
    easy_request_test.c
    easy_event_test.c
    easy_file_test.c
)


add_executable(${PROJECT_NAME} ${TEST_SOURCE})
target_link_libraries(${PROJECT_NAME}
PRIVATE
	easy::all
	OpenSSL::SSL
	OpenSSL::Crypto
	-lm
	${CMAKE_THREAD_LIBS_INIT}
)
add_test(${PROJECT_NAME} ${PROJECT_NAME})