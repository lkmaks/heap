//
// Created by M on 31.10.2018.
//

#ifndef HEAP_VECTOR_H
#define HEAP_VECTOR_H

#include <cstdlib>


template<class Key>
class Vector {
public:
    explicit Vector(size_t len = 0);
    explicit Vector(size_t, Key);
    ~Vector();

    size_t size() const;
    bool is_empty() const;
    Key &operator[](size_t i) const;

    void push_back(Key elem);
    void pop_back();
    void reverse();
private:
    Key *ptr;
    size_t len;

};


#endif //HEAP_VECTOR_H
