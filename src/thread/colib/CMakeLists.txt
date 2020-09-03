
# Set the project name
project (colib)

# Use c and asm
enable_language(C ASM)

# Set lib version
set(LIBCO_VERSION   0.5)

set(HEADERS
    coctx.h
)

set(SOURCES
coctx.cpp
coctx_swap.S
)

# Add a library with the above sources
add_library(${PROJECT_NAME} STATIC
    ${HEADERS}
    ${SOURCES}
)

add_library(easy::colib ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} 
    PUBLIC  
        ${PROJECT_SOURCE_DIR}
)