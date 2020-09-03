project(util_test)

set(TEST_SOURCE
    util_test.c
    easy_pool_test.c
    easy_buf_test.c
    easy_hash_test.c
    easy_string_test.c
    easy_inet_test.c
    easy_time_test.c
    easy_ref_test.c
    easy_lock_test.c
    easy_semaphore_test.c
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