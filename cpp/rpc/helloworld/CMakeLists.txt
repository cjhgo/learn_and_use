project(helloworld)

cmake_minimum_required(VERSION 3.2)

add_compile_options(-std=c++11)



list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

find_package(Protobuf REQUIRED)
find_package(GRPC REQUIRED)


add_subdirectory(src)