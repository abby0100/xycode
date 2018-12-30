cmake_minimum_required (VERSION 2.8)
project (xycode)

set (CMAKE_CXX_COMPILER "g++")
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

include_directories (src/include)

aux_source_directory (src DIR_SRC)
add_subdirectory (src)

add_executable (xycode ${DIR_SRC})
target_link_libraries (xycode xyutils)
