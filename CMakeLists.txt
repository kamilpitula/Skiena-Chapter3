cmake_minimum_required(VERSION 3.0.0)
project(Chapter3 VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(Stack STATIC stack.c stack.h)
add_library(LinkedList STATIC linkedList.c linkedList.h)
add_library(TicTacToe STATIC tictactoe.c tictactoe.h)
add_library(Anagram STATIC anagram.c anagram.h)
add_library(BinaryTree STATIC binaryTree.c binaryTree.h)

add_executable(Chapter3 main.c)
target_link_libraries(Chapter3 PUBLIC Stack)
target_link_libraries(Chapter3 PUBLIC LinkedList)
target_link_libraries(Chapter3 PUBLIC TicTacToe)
target_link_libraries(Chapter3 PUBLIC Anagram)
target_link_libraries(Chapter3 PUBLIC BinaryTree)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
