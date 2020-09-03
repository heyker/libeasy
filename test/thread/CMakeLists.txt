project(thread_test)

set(TEST_SOURCE
	thread_test.c
	easy_uthread_test.c
)


add_executable(${PROJECT_NAME} ${TEST_SOURCE})
target_link_libraries(${PROJECT_NAME}
PRIVATE
	easy::all
	-lm
	${CMAKE_THREAD_LIBS_INIT}
)
add_test(${PROJECT_NAME} ${PROJECT_NAME})