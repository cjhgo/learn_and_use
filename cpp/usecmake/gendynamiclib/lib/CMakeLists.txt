project(libtest_lib)

add_library(myfun SHARED myfun.cpp)
# add_library(myfun STATIC myfun.cpp)
Message("hhh" ${libtest_SOURCE_DIR})


add_library(usefun SHARED usefun.cpp)
TARGET_LINK_LIBRARIES(usefun myfun)

install(TARGETS usefun DESTINATION ${libtest_SOURCE_DIR}/deps/local)
install(TARGETS myfun DESTINATION ${libtest_SOURCE_DIR}/deps/local)

