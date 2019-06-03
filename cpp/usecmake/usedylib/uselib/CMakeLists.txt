project(libtest)

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "indir='${dir}'")
endforeach()

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY LINK_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "lidir='${dir}'")
endforeach()

add_executable(main main.cpp)
# TARGET_LINK_LIBRARIES(main libmyfun.a)
# TARGET_LINK_LIBRARIES(main usefun)