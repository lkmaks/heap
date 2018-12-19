#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../BinomialHeap.h"

using testing::Eq;
using namespace std;

/*
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
    int q = 5;
    BinomialHeap<int> h;
    Vector<BinomialHeap<int>::Pointer> arr;
    for (int i = 0; i < q; ++i) {
        arr.push_back(h.insert(i));
        cerr << i << ": ";
        for (int j = 0; j < h.roots.size(); ++j) {
            if (h.roots[j] != nullptr) {
                h.roots[j]->debug();
            }
        }
        cerr << endl;
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

        cerr << "! ";
        for (int j = 0; j < h.roots.size(); ++j) {
            if (h.roots[j] != nullptr) {
                h.roots[j]->debug();
            }
        }
        cerr << endl;

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
*/
