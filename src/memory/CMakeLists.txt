# Set the project name
project (memory)

# Add a library with the above sources
add_library(${PROJECT_NAME} STATIC
    easy_mem_pool.c
    easy_mem_page.c
    easy_mem_slab.c 
)
add_library(easy::memory ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC  ${PROJECT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME}
PUBLIC
	easy::include
)