#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../BinomialHeap.h"
#include "TimeReport.h"

using testing::Eq;
using namespace std;

TEST(InsertExtract, BinomialHeapCorrectnessTest) {
    int q = 100;
    BinomialHeap<int> h;

    ASSERT_EQ(h.is_empty(), true);
    for (int i = q - 1; i >= 0; --i) {
        h.insert(i);
    }
    for (int i = 0; i < q; ++i) {
        ASSERT_EQ(h.extract_min(), i);
    }
    ASSERT_EQ(h.is_empty(), true);
}

TEST(InsertEraseByPointer, BinomialHeapCorrectnessTest) {
    int q = 100;
    BinomialHeap<int> h;
    Vector<BinomialHeap<int>::Pointer> arr;
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

        ASSERT_EQ(arr[pos[0]].getKey(), h.get_min());
        ASSERT_EQ(h.is_empty(), false);
    }
    h.extract_min();
    ASSERT_EQ(h.is_empty(), true);
}


TEST(InsertEqualNumbers, BinomialHeapCorrectnessTest) {
    BinomialHeap<int> h;
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


TEST(ChangeMethod, BinomialHeapCorrectnessTest) {
    BinomialHeap<int> h;
    BinomialHeap<int>::Pointer ptr = h.insert(1);
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


TEST(MergeHeaps, BinomialHeapCorrectnessTests) {
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
            BinomialHeap<int> h1, h2;

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



TEST(GetMinOnEmptyHeap, BinomialHeapValidationTest) {
    BinomialHeap<int> h;
    ASSERT_THROW(h.get_min(), std::logic_error);
    BinomialHeap<int>::Pointer ptr = h.insert(1337);
    ASSERT_NO_THROW(h.get_min());
    h.erase(ptr);
    ASSERT_THROW(h.get_min(), std::logic_error);
}


TEST(ExtractMinOnEmptyHeap, BinomialHeapValidationTest) {
    BinomialHeap<int> h;
    ASSERT_THROW(h.extract_min(), std::logic_error);
    h.insert(1337);
    BinomialHeap<int>::Pointer ptr = h.insert(1339);
    ASSERT_NO_THROW(h.extract_min());
    h.erase(ptr);
    ASSERT_THROW(h.extract_min(), std::logic_error);
}


TEST(DISABLED_InsertExtract, BinomialHeapTimeTests) {
    time_t t0 = clock();

    int q = 5000000;
    BinomialHeap<int> h;
    for (int i = 0; i < q; ++i) {
        if (!h.is_empty() && !(rand() % 3)) {
            h.extract_min();
        }
        else {
            h.insert(i);
        }
    }

    int res = clock() - t0;

    reportTime("BinomialHeap inserts and extracts", res);
}

/// TODO: stress merge with FibonacciHeap