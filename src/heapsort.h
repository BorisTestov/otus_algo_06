#pragma once

#include "tester.h"
#include "abstractsort.h"

class HeapSort : public AbstractSort, public ITask {
public:
    std::vector<std::string> Run(std::vector<std::string> data, std::vector<int> args) override {
        convertData(data);
        sort();
        return {arrayToString()};
    }

private:
    void heapify(ull treeSize, ull rootIndex) {
        ull X = rootIndex;
        ull L = 2 * rootIndex + 1;
        ull R = 2 * rootIndex + 2;
        if (L < treeSize && array[L] > array[X])
            X = L;
        if (R < treeSize && array[R] > array[X])
            X = R;
        if (X != rootIndex) {
            std::swap(array[rootIndex], array[X]);
            heapify(treeSize, X);
        }
    }

    void sort() override {
        for (ull root = size / 2 - 1; root >= 0; --root)
            heapify(size, root);
        for (ull i = size - 1; i >= 0; --i) {
            std::swap(array[0], array[i]);
            heapify(i, 0);
        }
    }
};