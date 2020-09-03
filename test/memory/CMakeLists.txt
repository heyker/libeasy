project(memory_test)

set(TEST_SOURCE
    memory_test.c
    easy_mem_page_test.c
    easy_mem_pool_test.c
    easy_mem_slab_test.c
)


add_executable(${PROJECT_NAME} ${TEST_SOURCE})
target_link_libraries(${PROJECT_NAME}
PRIVATE
	easy::all
    -lm
    ${CMAKE_THREAD_LIBS_INIT}
)
add_test(${PROJECT_NAME} ${PROJECT_NAME})