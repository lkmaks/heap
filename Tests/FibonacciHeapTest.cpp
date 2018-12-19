#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../FibonacciHeap.h"

using testing::Eq;


TEST(InsertExtract, FibonacciHeapCorrectnessTests) {
    int q = 100;
    FibonacciHeap<int> h;

    ASSERT_EQ(h.is_empty(), true);
    for (int i = q - 1; i >= 0; --i) {
        h.insert(i);
    }
    for (int i = 0; i < q; ++i) {
        ASSERT_EQ(h.extract_min(), i);
    }
    ASSERT_EQ(h.is_empty(), true);
}


TEST(InsertEraseViaDecreaseByPointer, FibonacciHeapCorrectnessTest) {
    int q = 100;
    FibonacciHeap<int> h;
    Vector<FibonacciHeap<int>::Pointer> arr;
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
        h.decrease(arr[index], -1);
        h.extract_min();
        alive[index] = false;

        for (int j = id; j + 1 < pos.size(); ++j) {
            pos[j] = pos[j + 1];
        }
        pos.pop_back();

        ASSERT_EQ(arr[pos[0]].getKey(), h.get_min());
        ASSERT_EQ(h.is_empty(), false);
    }
    h.extract_min();
    ASSERT_EQ(h.is_empty(), true);
}


TEST(InsertEqualNumbers, FibonacciHeapCorrectnessTest) {
    FibonacciHeap<int> h;
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


TEST(MergeHeaps, FibonacciHeapCorrectnessTest) {
    srand(34234);
    Vector<int> qs;
    qs.push_back(1);
    qs.push_back(2);
    qs.push_back(3);
    qs.push_back(4);
    qs.push_back(5);
    qs.push_back(100);

    for (int ic = 0; ic < qs.size(); ++ic) {
        int q = qs[ic];
        for (int j = 0; j < 10; ++j) {
            FibonacciHeap<int> h1, h2;

            for (int i = 0; i < q; ++i) {
                if (rand() % 2) {
                    h1.insert(i);
                } else {
                    h2.insert(i);
                }
            }
            h1.merge(h2);
            ASSERT_EQ(h2.is_empty(), true);
            for (int i = 0; i < q; ++i) {
                ASSERT_EQ(h1.extract_min(), i);
            }
        }
    }
}