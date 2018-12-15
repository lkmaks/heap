//
// Created by M on 21.11.2018.
//

#ifndef HEAP_BINOMIALHEAP_H
#define HEAP_BINOMIALHEAP_H

#include "Vector.h"
#include "Vector.cpp"

#include <iostream>


template <class Key>
class BinomialHeap {
private:
    class Node;

public:
    class Pointer {
        friend BinomialHeap<Key>;
    public:
        Node *ptr;
        explicit Pointer(Node *ptr_);
    public:
        Pointer();
    };

    bool is_empty() const;
    Pointer insert(Key);
    Key get_min() const;
    Key extract_min();
    void merge(BinomialHeap &otherHeap);
    void erase(Pointer ptr);
    void change(Pointer, Key);

private:
    class Node {
        friend BinomialHeap<Key>;
    public:
        size_t order;
        Node *first_child, *next_brother, *parent;
        Key key;
        Node(Key);

        void debug() {
            std::cerr << key << "{";
            Node *cur = first_child;
            while (cur != nullptr) {
                cur->debug();
                cur = cur->next_brother;
            }
            std::cerr << "}";
        }
    };

    Vector<Node*> roots;
    Node *min_node;

    Node* merge_binomial_trees(Node *a, Node *b);
    void attach(Node *root, Node *child);
    void add_nodes(Vector<Node*>&, Vector<Node*>&);
    void update_min_node();
};


#endif //HEAP_BINOMIALHEAP_H
