
cmake_minimum_required(VERSION 2.8)

project(libtest)

include_directories(
  ${libtest_SOURCE_DIR}/include
)

link_directories(
  ${libtest_SOURCE_DIR}/deps/local
)
MESSAGE(STATUS "???" ${CMAKE_INSTALL_PREFIX})
subdirs(uselib)