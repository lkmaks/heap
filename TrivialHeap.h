//
// Created by M on 05.11.2018.
//

#ifndef HEAP_TRIVIALHEAP_H
#define HEAP_TRIVIALHEAP_H

#include "Vector.h"
#include "Vector.cpp"

template<typename Key>
class TrivialHeap {
private:
    Vector<Key> keys;
public:

    TrivialHeap();
    bool is_empty() const;
    void insert(Key key);
    Key get_min() const;
    Key extract_min();
};


#endif //HEAP_TRIVIALHEAP_H
