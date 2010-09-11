cmake_minimum_required (VERSION 2.6)
project (kdtree)

set (LIBRARY_OUTPUT_PATH "./lib")

include_directories (.)

set (SRCS ./kdtree.h)
link_libraries (pthread)
add_library (kdtree SHARED ${SRCS})

set_target_properties(kdtree PROPERTIES LINKER_LANGUAGE C)
