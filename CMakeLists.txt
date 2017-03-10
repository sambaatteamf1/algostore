cmake_minimum_required(VERSION 3.5)

set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

enable_language(C)
enable_language(CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CFLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CFLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CFLAGS}")
enable_testing()

add_subdirectory(collection)
add_subdirectory(algo)
add_subdirectory(util)
add_subdirectory(test)
