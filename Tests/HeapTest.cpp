#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Heap.h"
#include "../Heap.cpp"

#include <bits/stdc++.h>
using namespace std;

using testing::Eq;


TEST(InsertExtract, HeapCorrectnessTests) {
    int q = 100;
    Heap<int> h;

    ASSERT_EQ(h.is_empty(), true);
    for (int i = q - 1; i >= 0; --i) {
        h.insert(i);
    }
    for (int i = 0; i < q; ++i) {
        ASSERT_EQ(h.extract_min(), i);
    }
    ASSERT_EQ(h.is_empty(), true);
}


TEST(InsertEraseByPointer, HeapCorrectnessTest) {
    int q = 100;
    Heap<int> h;
    Vector<Heap<int>::Pointer> arr;
    for (int i = 0; i < q; ++i) {
        arr.push_back(h.insert(i));
    }
    Vector<bool> alive(arr.size(), true);
    srand(1791791791);
    for (int i = 0; i < q - 1; ++i) {
        int id = rand() % (q - i);
        Vector<int> pos;
        for (int j = 0; j < q; ++j) {
            if (alive[j]) {
                pos.push_back(j);
            }
        }
        int index = pos[id];
        h.erase(arr[index]);
        alive[index] = false;

        for (int j = id; j + 1 < pos.size(); ++j) {
            pos[j] = pos[j + 1];
        }
        pos.pop_back();

        ASSERT_EQ(arr[pos[0]].getVal(), h.get_min());
        ASSERT_EQ(h.is_empty(), false);
    }
    h.extract_min();
    ASSERT_EQ(h.is_empty(), true);
}


TEST(InsertEqualNumbers, HeapCorrectnessTest) {
    Heap<int> h;
    h.insert(1);
    h.insert(1);
    h.insert(2);
    h.insert(1);
    ASSERT_EQ(h.extract_min(), 1);
    ASSERT_EQ(h.extract_min(), 1);
    ASSERT_EQ(h.extract_min(), 1);
    ASSERT_EQ(h.extract_min(), 2);
    ASSERT_EQ(h.is_empty(), true);
}


TEST(ChangeMethod, HeapCorrectnessTest) {
    Heap<int> h;
    Heap<int>::Pointer ptr = h.insert(1);
    h.insert(2);
    h.insert(3);
    ASSERT_EQ(h.get_min(), 1);
    h.change(ptr, 4);
    ASSERT_EQ(h.get_min(), 2);
    h.extract_min();
    h.extract_min();
    ASSERT_EQ(h.extract_min(), 4);
    ASSERT_EQ(h.is_empty(), true);
}


TEST(IteratorConstructor, HeapCorrectnessTest) {
    int q = 100;
    int *a = new int[q];
    for (int i = 0; i < q; ++i) {
        a[i] = i;
    }
    Heap<int> h(a, a + q);
    for (int i = 0; i < q; ++i) {
        ASSERT_EQ(h.extract_min(), i);
    }
    ASSERT_EQ(h.is_empty(), true);
}


TEST(GetMinOnEmptyHeap, HeapValidationTest) {
    Heap<int> h;
    ASSERT_THROW(h.get_min(), std::logic_error);
    Heap<int>::Pointer ptr = h.insert(1337);
    ASSERT_NO_THROW(h.get_min());
    h.erase(ptr);
    ASSERT_THROW(h.get_min(), std::logic_error);
}


TEST(ExtractMinOnEmptyHeap, HeapValidationTest) {
    Heap<int> h;
    ASSERT_THROW(h.extract_min(), std::logic_error);
    h.insert(1337);
    Heap<int>::Pointer ptr = h.insert(1339);
    ASSERT_NO_THROW(h.extract_min());
    h.erase(ptr);
    ASSERT_THROW(h.extract_min(), std::logic_error);
}


