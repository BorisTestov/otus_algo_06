#pragma once

#include "tester.h"

class InsertionSort : public ITask {
public:
    std::vector<std::string> Run(std::vector<std::string> data) override {
        convertData(data);
        sort();
        return {arrayToString()};
    }

    ~InsertionSort() {
        delete[] array;
    }

private:
    uint32_t *array;
    uint32_t size;

    void convertData(const std::vector<std::string> &data) {
        size = std::stoul(data[0]);
        array = new uint32_t[size];
        std::stringstream ss(data[0]);
        std::string item;
        uint32_t index = 0;
        while (std::getline(ss, item, ' ')) {
            array[index] = std::stoul(item);
            ++index;
        }
    }

    std::string arrayToString() {
        std::stringstream ss;
        ss << array[0];
        std::for_each(array + 1, array + size, [&ss](int n) {
            ss << " " << n;
        });
        return ss.str();
    }

    void sort() {
    }
};