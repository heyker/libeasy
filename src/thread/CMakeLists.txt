# Set the project name
project (thread)

add_subdirectory(colib)

set(HEADERS
    easy_uthread.h
)

set(SOURCES
    easy_uthread.c
)

# Add a library with the above sources
add_library(${PROJECT_NAME} STATIC
    ${HEADERS}
    ${SOURCES}
)

add_library(easy::thread ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} 
    PUBLIC  
        ${PROJECT_SOURCE_DIR}
)
target_link_libraries(${PROJECT_NAME}
    easy::colib
    easy::include
    easy::util
)