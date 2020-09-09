project(samples)

include_directories(${OPENSSL_INCLUDE_DIR})
list(APPEND LIB_LIST ${OPENSSL_LIBRARIES})
		
add_executable(echo_client1 echo_client.c)
target_link_libraries(echo_client1
PRIVATE
	easy::all
	OpenSSL::SSL
	OpenSSL::Crypto
	${CMAKE_THREAD_LIBS_INIT}
	-lm
)

add_executable(echo_server1 echo_server.c)
target_link_libraries(echo_server1
PRIVATE
	easy::all
	OpenSSL::SSL
	OpenSSL::Crypto
	${CMAKE_THREAD_LIBS_INIT}
	-lm
)

file(GLOB_RECURSE mains ${CMAKE_CURRENT_SOURCE_DIR}  "*.c" "*.cpp")
message(STATUS ${mains})
foreach(mainfile IN LISTS mains)
    # Get file name without directory
    get_filename_component(mainname ${mainfile} NAME_WE)
    add_executable(${mainname} ${mainfile})
    target_link_libraries(${mainname} 
    PRIVATE
        easy::all
        OpenSSL::SSL
        OpenSSL::Crypto
        ${CMAKE_THREAD_LIBS_INIT}
        -lm
)
endforeach()