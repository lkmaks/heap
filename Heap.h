//
// Created by M on 30.10.2018.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H


#include <cstdlib>
#include "Vector.h"
#include "Vector.cpp"



template<class Key>
class Heap {
private:
    class Node;

public:

    class Pointer {
        friend Heap<Key>;
    private:
        Node *ptr;
        Pointer(Node *ptr_);
    public:
        Pointer();
    };

    Heap();

    template <class Iterator>
    Heap(Iterator begin, Iterator end);

    bool is_empty() const;
    Pointer insert(Key);
    void erase(Pointer);
    Key extract_min();
    void change(Pointer, Key);
    Key get_min() const;
    void optimize(size_t, size_t);
private:

    class Node {
        friend Heap<Key>;
    private:
        Key val;
        size_t index;
        Node(Key val_, size_t index_ = 0);
    };

    Vector<Node*> nodes;

    void swap_nodes(size_t i, size_t j);
    void siftUp(size_t index);
    void siftDown(size_t index);
};

#endif //HEAP_HEAP_H
