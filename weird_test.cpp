//
// Created by M on 19.11.2018.
//

#include <iostream>
#include "Heap.h"
#include "Heap.cpp"
#include "TrivialHeap.h"
#include "TrivialHeap.cpp"

int main() {

    std::freopen("C:\\Users\\M\\alg\\labs\\heap\\input.txt", "rt", stdin);

    Heap<int> heap = Heap<int>();
    TrivialHeap<int> trivial_heap = TrivialHeap<int>();

    while (true) {
        std::string dec;
        std::cin >> dec;
        std::cerr << dec << std::endl;
        if (dec == "is_empty") {
            if (heap.is_empty() != trivial_heap.is_empty()) {
                std::cerr << "Error 0" << std::endl;
            }
        }
        else if (dec == "insert") {
            int x;
            std::cin >> x;
            heap.insert(x);
            trivial_heap.insert(x);
        }
        else if (dec == "get_min") {
            if (heap.get_min() != trivial_heap.get_min()) {
                std::cerr << "Error 1" << std::endl;
            }
        }
        else if (dec == "extract_min") {
            int a = heap.extract_min(), b = trivial_heap.extract_min();
            if (a != b) {
                std::cerr << "Error 2" << std::endl;
                std::cerr << a << std::endl;
                std::cerr << b << std::endl;
            }
        }
        else {
            break;
        }
    }

    return 0;
}