cmake_minimum_required(VERSION 3.5.1)

project(normal C CXX)

add_subdirectory(src)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

FIND_PACKAGE(Protobuf REQUIRED)
find_package(GRPC REQUIRED)