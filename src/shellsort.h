#pragma once

#include "tester.h"
#include "abstractsort.h"

class ShellSort : public AbstractSort, public ITask {
public:
    std::vector<std::string> Run(std::vector<std::string> data, std::vector<int> args) override {
        step = args[0];
        convertData(data);
        sort();
        return {arrayToString()};
    }

private:
    int step;

    void sort() override {
        assert(step <= size || size < 2);
        for (ull gap = size / step; gap > 0; gap /= step) {
            for (ull i = 0; i + gap < size; ++i) {
                ull j = i + gap;
                ull temp = array[j];
                while (j - gap >= 0 && array[j - gap] > temp) {
                    array[j] = array[j - gap];
                    j -= gap;
                }
                array[j] = temp;
            }
        }
    }
};