cmake_minimum_required(VERSION 3.9)
project(heap)

set(CMAKE_CXX_STANDARD 11)

add_executable(heap main.cpp Heap.cpp Heap.h Vector.cpp Vector.h TrivialHeap.cpp TrivialHeap.h BinomialHeap.cpp BinomialHeap.h FibonacciHeap.cpp FibonacciHeap.h LinkedList.cpp LinkedList.h)