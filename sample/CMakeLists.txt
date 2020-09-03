project(samples)

include_directories(${OPENSSL_INCLUDE_DIR})
list(APPEND LIB_LIST ${OPENSSL_LIBRARIES})
		
add_executable(echo_client echo_client.c)
target_link_libraries(echo_client
PRIVATE
	easy::all
	OpenSSL::SSL
	OpenSSL::Crypto
	${CMAKE_THREAD_LIBS_INIT}
	-lm
)

add_executable(echo_server echo_server.c)
target_link_libraries(echo_server
PRIVATE
	easy::all
	OpenSSL::SSL
	OpenSSL::Crypto
	${CMAKE_THREAD_LIBS_INIT}
	-lm
)