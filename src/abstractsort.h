#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using ull = long long;

class AbstractSort {
public:
    AbstractSort() = default;

    ~AbstractSort() {
        delete[] array;
    }

protected:
    ull *array = nullptr;
    ull size = 0;

    virtual void sort() = 0;

    void convertData(const std::vector<std::string> &data) {
        size = std::stoll(data[0]);
        array = new ull[size];
        std::stringstream ss(data[1]);
        std::string item;
        ull index = 0;
        while (std::getline(ss, item, ' ')) {
            array[index] = std::stoll(item);
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

    void print() {
        if (size == 0) return;
        std::cout << array[0];
        for (int i = 1; i < size; ++i) {
            std::cout << " " << array[i];
        }
        std::cout << "\n";
    }
};