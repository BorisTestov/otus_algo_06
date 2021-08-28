#pragma once

#include "tester.h"
#include "abstractsort.h"

class InsertionSort : public AbstractSort, public ITask {
public:
    std::vector<std::string> Run(std::vector<std::string> data, std::vector<int> args) override {
        convertData(data);
        sort();
        return {arrayToString()};
    }

private:
    void sort() override {
        for (ull i = 1; i < size; ++i) {
            ull x = array[i];
            ull indexToInsert = binarySearch(0, i - 1, x);
            std::copy(array + indexToInsert, array + i, array + indexToInsert + 1);
            array[indexToInsert] = x;
        }
    }

    ull binarySearch(ull startIndex, ull stopIndex, ull value) {
        ull indexToInsert = 0;
        while (startIndex <= stopIndex) {
            indexToInsert = (startIndex + stopIndex) / 2;
            if (array[indexToInsert] > value) {
                stopIndex = indexToInsert - 1;
            } else if (array[indexToInsert] < value) {
                startIndex = indexToInsert + 1;
                indexToInsert = startIndex;
            } else {
                break;
            }
        }
        return indexToInsert;
    }
};