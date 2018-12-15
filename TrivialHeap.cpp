//
// Created by M on 05.11.2018.
//

#include <stdexcept>
#include "TrivialHeap.h"


template <typename Key>
TrivialHeap<Key>::TrivialHeap() {}


template <typename Key>
bool TrivialHeap<Key>::is_empty() const {
    return keys.is_empty();
}

template <typename Key>
void TrivialHeap<Key>::insert(Key key) {
    keys.push_back(key);
}

template <typename Key>
Key TrivialHeap<Key>::get_min() const {
    if (is_empty()) {
        throw std::logic_error("TrivialHeap instance is empty");
    }
    Key res = keys[0];
    for (int i = 0; i < keys.size(); ++i) {
        if (keys[i] < res) {
            res = keys[i];
        }
    }
    return res;
}

template <typename Key>
Key TrivialHeap<Key>::extract_min() {
    if (is_empty()) {
        throw std::logic_error("TrivialHeap instance is empty");
    }
    int min_id = 0;
    for (int i = 0; i < keys.size(); ++i) {
        if (keys[i] < keys[min_id]) {
            min_id = i;
        }
    }

    Key return_value = keys[min_id];

    for (int i = min_id; i + 1 < keys.size(); ++i) {
        swap(keys[i], keys[i + 1]);
    }
    keys.pop_back();

    return return_value;
}

