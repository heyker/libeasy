# Set the project name
project (util)

set(HEADERS
    easy_buf.h
    easy_hash.h
    easy_pool.h
    easy_string.h
    easy_inet.h
    easy_time.h
    easy_array.h
    easy_ref.h
    easy_lock.h
    easy_semaphore.h
)

set(SOURCES
    easy_buf.c
    easy_hash.c
    easy_pool.c
    easy_string.c
    easy_inet.c
    easy_time.c
    easy_array.c
    easy_ref.c
    easy_lock.c
    easy_semaphore.c
)

# Add a library with the above sources
add_library(${PROJECT_NAME} STATIC
    ${HEADERS}
    ${SOURCES}
)
add_library(easy::util ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC  ${PROJECT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME}
PUBLIC
	easy::include
)