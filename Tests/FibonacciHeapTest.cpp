#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../FibonacciHeap.h"
#include "TimeReport.h"

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


TEST(InsertEraseViaDecreaseByPointer, FibonacciHeapCorrectnessTests) {
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


TEST(InsertEqualNumbers, FibonacciHeapCorrectnessTests) {
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


TEST(MergeHeaps, FibonacciHeapCorrectnessTests) {
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
                }
                else {
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


TEST(GetDecreaseExtract, FibonacciHeapCorrectnessTests) {
    FibonacciHeap<int> h;
    FibonacciHeap<int>::Pointer ptr1 = h.insert(1);
    FibonacciHeap<int>::Pointer ptr2 = h.insert(2);
    FibonacciHeap<int>::Pointer ptr3 = h.insert(3);
    ASSERT_EQ(h.get_min(), 1);
    h.decrease(ptr2, 1);
    ASSERT_EQ(h.get_min(), 1);
    h.decrease(ptr3, -1);
    ASSERT_EQ(h.get_min(), -1);
    h.extract_min();
    ASSERT_EQ(h.get_min(), 1);
    h.extract_min();
    ASSERT_EQ(h.get_min(), 1);
    h.extract_min();
    ASSERT_EQ(h.is_empty(), true);
}


TEST(GetMin, FibonacciHeapValidationTests) {
    FibonacciHeap<int> h;
    ASSERT_THROW(h.get_min(), std::logic_error);
    h.insert(1);
    ASSERT_NO_THROW(h.get_min());
}


TEST(ExtractMin, FibonacciHeapValidationTests) {
    FibonacciHeap<int> h;
    ASSERT_THROW(h.extract_min(), std::logic_error);
    h.insert(1);
    ASSERT_NO_THROW(h.extract_min());
}


TEST(Decrease, FibonacciHeapValidationTests) {
    FibonacciHeap<int> h;
    FibonacciHeap<int>::Pointer ptr = h.insert(1);
    ASSERT_THROW(h.decrease(ptr, 2), std::invalid_argument);
    ASSERT_NO_THROW(h.decrease(ptr, -10));
}


TEST(InsertExtract, FibonacciHeapTimeTests) {
    time_t t0 = clock();

    int q = 5000000;
    FibonacciHeap<int> h;
    for (int i = 0; i < q; ++i) {
        if (!h.is_empty() && !(rand() % 3)) {
            h.extract_min();
        }
        else {
            h.insert(i);
        }
    }
    int res = clock() - t0;

    reportTime("FibonacciHeap", res);
}