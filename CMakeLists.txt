cmake_minimum_required(VERSION 3.10)
project(leetcode VERSION 1.0)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 14)

add_compile_options(-DLOCAL)

add_executable(953.out 953.验证外星语词典.cpp)
add_executable(215.out 215.数组中的第k个最大元素.cpp)
add_executable(segment_tree.out learn/segment_tree.cpp)
add_executable(327.out 327.区间和的个数.cpp)
add_executable(5557.out contest/5557.cpp)
add_executable(5558.out contest/5558.cpp)
add_executable(5559.out contest/5559.cpp)
