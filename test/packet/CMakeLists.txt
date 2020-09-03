project(packet_test)

set(TEST_SOURCE
    packet_test.c
    easy_http_handler_test.c
    easy_kfc_handler_test.c
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