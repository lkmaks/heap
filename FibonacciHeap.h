//
// Created by M on 11.12.2018.
//

#ifndef HEAP_FIBONACCIHEAP_H
#define HEAP_FIBONACCIHEAP_H

#include <cstdlib>

template <class Key>
class FibonacciHeap {
private:
    class Node;
public:
    class Pointer {
        friend FibonacciHeap<Key>;
    private:
        Node *ptr;
        Pointer(Node *ptr_);
    public:
        Pointer();
    };

    FibonacciHeap();

    bool is_empty() const;
    Pointer insert(Key);
    Key get_min() const;
    Key extract_min();
    void merge(FibonacciHeap &otherHeap);
    void decrease(Pointer, Key);
private:
    class Node {
        friend FibonacciHeap<Key>;
    private:
        Key key;
        Node *parent, *child, *prev, *next;
        size_t degree;
        bool mark;
        Node(Key);
    };

    Node *min_node;

    void attach(Node*, Node*);
    void add_node_to_roots(Node*);
    void consolidate(Node*);
    void cut(Node*);
    void cascading_cut(Node*);
};


#endif //HEAP_FIBONACCIHEAP_H
