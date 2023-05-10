cmake_minimum_required(VERSION 3.0.0)
project(Chapter3 VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(Stack STATIC stack.c stack.h)

add_executable(Chapter3 main.c)
target_link_libraries(Chapter3 PUBLIC Stack)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
