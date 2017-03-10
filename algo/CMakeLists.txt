cmake_minimum_required(VERSION 3.5)

project(algoc VERSION 0.0.1)

file(GLOB source_files "*.c")
file(GLOB header_files "include/*.h")

add_library(${PROJECT_NAME} SHARED ${source_files})
add_library(${PROJECT_NAME}_static STATIC ${source_files})

include_directories("./")
include_directories("../util/")
include_directories("../collection/src/include")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
