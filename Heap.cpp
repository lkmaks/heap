//
// Created by M on 30.10.2018.
//

#include <stdexcept>
#include "heap.h"


template<class Key>
Heap<Key>::Node::Node(Key val_, size_t index_) {
    val = val_;
    index = index_;
}


template <class Key>
Heap<Key>::Pointer::Pointer() {
    ptr = nullptr;
}

template <class Key>
Heap<Key>::Pointer::Pointer(Node *ptr_) {
    ptr = ptr_;
}



template <class Key>
Heap<Key>::Heap() {
    Node *node = new Node(Key());
    nodes.push_back(node);
}


template <class Key>
void Heap<Key>::swap_nodes(size_t i, size_t j) {
    nodes[i]->index = j;
    nodes[j]->index = i;
    swap(nodes[i], nodes[j]);
}


template <class Key>
void Heap<Key>::siftUp(size_t index) {
    while (index > 1 && nodes[index]->val < nodes[index / 2]->val) {
        swap_nodes(index, index / 2);
        index /= 2;
    }
}


template<class Key>
void Heap<Key>::siftDown(size_t index) {
    while (index * 2 < nodes.size()) {
        size_t min_id = index * 2;
        if (index * 2 + 1 < nodes.size() && nodes[index * 2 + 1]->val < nodes[min_id]->val) {
            min_id = index * 2 + 1;
        }
        if (nodes[min_id]->val < nodes[index]->val) {
            swap_nodes(min_id, index);
            index = min_id;
        }
        else {
            break;
        }
    }
}


template <class Key>
bool Heap<Key>::is_empty() const {
    return nodes.size() == 1;
}


template<class Key>
typename Heap<Key>::Pointer Heap<Key>::insert(Key key) {
    Node *nw = new Node(key, nodes.size());
    nodes.push_back(nw);
    siftUp(nodes.size() - 1);
    return Pointer(nw);
}


template<class Key>
Key Heap<Key>::get_min() const {
    if (is_empty()) {
        throw std::logic_error("Heap instance is empty");
    }
    return nodes[1]->val;
}

template<class Key>
Key Heap<Key>::extract_min() {
    if (is_empty()) {
        throw std::logic_error("Heap instance is empty");
    }

    Key return_value = nodes[1]->val;

    swap_nodes(1, nodes.size() - 1);
    delete nodes[nodes.size() - 1];
    nodes.pop_back();
    siftDown(1);

    return return_value;
}


template <class Key>
void Heap<Key>::erase(Heap<Key>::Pointer ptr) {
    size_t index = ptr.ptr->index;
    swap_nodes(index, nodes.size() - 1);
    nodes.pop_back();
    siftDown(index);
}


template <class Key>
void Heap<Key>::change(Pointer ptr, Key key) {
    ptr.ptr->val = key;
    siftUp(ptr.ptr->index);
    siftDown(ptr.ptr->index);
}


template <class Key>
template<class Iterator>
Heap<Key>::Heap(Iterator begin, Iterator end) {
    Heap<Key>();
    while (begin != end) {
        insert(*begin);
        ++begin;
    }
}

template <class Key>
void Heap<Key>::optimize(size_t insertCount, size_t extractCount) {

}
