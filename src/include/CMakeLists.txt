# Set the project name
project (include)

# Add a library with the above sources
add_library(${PROJECT_NAME} INTERFACE)
add_library(easy::include ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${PROJECT_SOURCE_DIR}
)
target_sources(${PROJECT_NAME}
INTERFACE
    ${PROJECT_SOURCE_DIR}/easy_atomic.h
    ${PROJECT_SOURCE_DIR}/easy_define.h
    ${PROJECT_SOURCE_DIR}/easy_list.h
)
