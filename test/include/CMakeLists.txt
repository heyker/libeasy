project(include_test)

set(TEST_SOURCE
	include_test.c
    easy_atomic_test.c
    easy_list_test.c
)


add_executable(${PROJECT_NAME} ${TEST_SOURCE})
target_link_libraries(${PROJECT_NAME}
PRIVATE
	easy::all
	-lm
	${CMAKE_THREAD_LIBS_INIT}
)
add_test(${PROJECT_NAME} ${PROJECT_NAME})