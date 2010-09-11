cmake_minimum_required (VERSION 2.6)
project (kdtree)

set (LIBRARY_OUTPUT_PATH "./lib")

include_directories (.)

# lib/libkdtree.so
set (SRCS ./kdtree.cpp)
link_libraries (pthread)
add_library (kdtree SHARED ${SRCS})
set_target_properties(kdtree PROPERTIES LINKER_LANGUAGE CXX)

# examples
add_subdirectory(examples)



