cmake_minimum_required (VERSION 2.8.2)
project (kdtree)

set (LIBRARY_OUTPUT_PATH lib)

include_directories (include)

# lib/libkdtree.so
set (SRCS src/kdtree.cpp)
link_libraries (pthread)
add_library (kdtree SHARED ${SRCS})
set_target_properties(kdtree PROPERTIES LINKER_LANGUAGE CXX)

# examples
add_subdirectory(examples)

# install
INSTALL(TARGETS kdtree
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

INSTALL(FILES include/kdtree.h DESTINATION include)


