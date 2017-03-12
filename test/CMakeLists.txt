cmake_minimum_required(VERSION 3.5)

set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

enable_language(C)
enable_language(CXX)

set(CFLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CFLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CFLAGS}")

include_directories("../collection/src/include")
include_directories("../algo")
include_directories("../util")

add_executable(insertion-sort-list insertion-sort-list.c)

link_directories("../algo")
link_directories("../collection")
link_directories("../util")

target_link_libraries(insertion-sort-list algoc util collectc)

set_target_properties(insertion-sort-list
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

