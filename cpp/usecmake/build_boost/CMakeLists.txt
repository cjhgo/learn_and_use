project(build_boost)


cmake_minimum_required(VERSION 2.8)
set(CMAKE_VERBOSE_MAKEFILE ON)
include(ExternalProject)
include_directories(
  /tmp/deps/local/include)


set(CMAKE_CXX_STANDARD 11)

ExternalProject_Add(libbz2
  PREFIX /tmp/deps/libbz2
  URL /tmp/dist/bzip2-1.0.6.tar.gz
  URL_MD5 00b516f4704d4a7cb50a1d97e6e8e15b
  INSTALL_DIR /tmp/deps/local
  CONFIGURE_COMMAND ""
  PATCH_COMMAND patch -N -p0 -i /tmp/patches/libbz2_fpic.patch || true
  BUILD_IN_SOURCE 1
  BUILD_COMMAND make install PREFIX=<INSTALL_DIR>
  INSTALL_COMMAND "" )

ExternalProject_Add(boost
  PREFIX /tmp/deps/boost
  URL /tmp/dist/boost_1_53_0.tar.gz
  URL_MD5 57a9e2047c0f511c4dfcf00eb5eb2fbb
  BUILD_IN_SOURCE 1
  CONFIGURE_COMMAND
  ./bootstrap.sh
  --with-libraries=filesystem
  --with-libraries=program_options
  --with-libraries=system
  --with-libraries=iostreams
  --with-libraries=date_time
  --with-libraries=random
  --with-libraries=context
  --prefix=<INSTALL_DIR>
  BUILD_COMMAND
  C_INCLUDE_PATH=/tmp/deps/local/include
  CPLUS_INCLUDE_PATH=/tmp/deps/local/include
  LIBRARY_PATH=/tmp/deps/local/lib
  ./b2 install link=static variant=release threading=multi runtime-link=static
  INSTALL_COMMAND ""
  INSTALL_DIR /tmp/deps/local )
set(BOOST_ROOT /tmp/deps/local )
set(BOOST_LIBS_DIR /tmp/deps/local/lib)
message(STATUS ",,,," ${BOOST_LIBS_DIR})
set(Boost_LIBRARIES
  ${BOOST_LIBS_DIR}/libboost_filesystem.a
  ${BOOST_LIBS_DIR}/libboost_program_options.a
  ${BOOST_LIBS_DIR}/libboost_system.a
  ${BOOST_LIBS_DIR}/libboost_iostreams.a
  ${BOOST_LIBS_DIR}/libboost_context.a
  ${BOOST_LIBS_DIR}/libboost_date_time.a)
message(STATUS "Boost libs: " ${Boost_LIBRARIES})  

message(STATUS "line 58: " ${build_boost_SOURCE_DIR})  
ExternalProject_Add(openmpi
  PREFIX ${build_boost_SOURCE_DIR}/deps/openmpi
  URL ${build_boost_SOURCE_DIR}/openmpi-1.4.5.tar.gz
  CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=<INSTALL_DIR> --disable-mpi-f77
  INSTALL_DIR ${build_boost_SOURCE_DIR}/deps/local)
set(MPI_FOUND True)

set(MPI_LIBRARY
${build_boost_SOURCE_DIR}/deps/local/lib/libmpi.so
)
set(MPI_EXTRA_LIBRARY
${build_boost_SOURCE_DIR}/deps/local/lib/libmpi_cxx.so
)
set(MPI_INCLUDE_PATH
${build_boost_SOURCE_DIR}/deps/local/include
)
add_definitions(-DHAS_MPI)
include_directories(${MPI_INCLUDE_PATH})




message(STATUS "MPI_LIBRARY,,,," ${MPI_LIBRARY})
message(STATUS "MPI_EXTRA_LIBRARY,,,," ${MPI_EXTRA_LIBRARY})
message(STATUS "MPI_INCLUDE_PATH,,,," ${MPI_INCLUDE_PATH})

#link_libraries(${Boost_LIBRARIES})
add_executable(hellompi hellompi.c)
add_dependencies(hellompi openmpi)
target_link_libraries(hellompi ${MPI_LIBRARY} ${MPI_EXTRA_LIBRARY})
# target_link_libraries( use_boost ${Boost_LIBRARIES})

