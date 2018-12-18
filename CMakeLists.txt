cmake_minimum_required(VERSION 3.9)
project(heap)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib\\googletest-master)
include_directories(lib\\googletest-master\\googletest\\include)
include_directories(lib\\googletest-master\\googlemock\\include)


add_executable(heap main.cpp Heap.cpp Heap.h Vector.cpp Vector.h TrivialHeap.cpp
        TrivialHeap.h BinomialHeap.cpp BinomialHeap.h FibonacciHeap.cpp FibonacciHeap.h Tests/HeapTest.cpp)
target_link_libraries(heap gtest gtest_main)
