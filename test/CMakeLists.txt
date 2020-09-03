project(test)

include_directories(${OPENSSL_INCLUDE_DIR})
include_directories(${PROJECT_SOURCE_DIR})
list(APPEND LIB_LIST ${OPENSSL_LIBRARIES})

add_subdirectory(include)
add_subdirectory(io)
add_subdirectory(memory)
add_subdirectory(packet)
add_subdirectory(thread)
add_subdirectory(util)
