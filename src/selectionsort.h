#pragma once

#include "tester.h"
#include "abstractsort.h"

class SelectionSort : public AbstractSort, public ITask {
public:
    std::vector<std::string> Run(std::vector<std::string> data, std::vector<int> args) override {
        convertData(data);
        sort();
        return {arrayToString()};
    }

private:
    void sort() override {
        for (ull i = size - 1; i > 0; --i) {
//            ull maxIndex = std::distance(array, std::max_element(array, array + i + 1));
            ull maxIndex = 0;
            ull maxElement = array[maxIndex];
            for (ull j = 0; j <= i; ++j) {
                if (array[j] > maxElement) {
                    maxIndex = j;
                    maxElement = array[maxIndex];
                }
            }
            std::swap(array[maxIndex], array[i]);
        }
    }
};