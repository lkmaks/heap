cmake_minimum_required(VERSION 3.9)
project(heap)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib\\googletest-master)
include_directories(lib\\googletest-master\\googletest\\include)
include_directories(lib\\googletest-master\\googlemock\\include)


add_executable(heap main.cpp Heap.h Vector.h
        BinomialHeap.h FibonacciHeap.h Tests/HeapTest.cpp Tests/BinomialHeapTest.cpp Tests/FibonacciHeapTest.cpp Tests/TimeReport.h)
target_link_libraries(heap gtest gtest_main)
