#pragma once

#include <string>
#include <memory>
#include <fstream>
#include <utility>
#include <vector>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <sstream>
#include <cassert>
#include <cstdlib>

inline bool fileExists(const std::string &name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

class ITask {
public:
    virtual std::vector<std::string> Run(std::vector<std::string> data, std::vector<int> args) = 0;
};

template<class T>
class Tester {
public:
    Tester() = default;

    std::vector<std::string>
    RunTests(const std::string &path, bool verbose = false, bool assertOnError = false, double tolerance = 0.0) {
        this->_verbose = verbose;
        this->_assertOnError = assertOnError;
        this->_tolerance = tolerance;
        int testNumber = 0;
        std::vector<std::string> times;
        std::cout << "Tester started: " << std::endl;
        while (true) {
            std::cout << "_______________________________" << std::endl;
            std::string inFile = path + "/test." + std::to_string(testNumber) + ".in";
            std::string outFile = path + "/test." + std::to_string(testNumber) + ".out";
            if (!fileExists(inFile) || !fileExists(outFile))
                break;
            auto start = std::chrono::high_resolution_clock::now();
            bool result = RunTest(inFile, outFile);
            auto stop = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
            times.push_back(std::to_string(elapsed) + "ms");
            std::string testResult = "Passed";
            if (!result) {
                testResult = "Failed";
            }
            std::cout << "Test#" << testNumber << "\t" << testResult << "\t" << elapsed << "ms"
                      << std::endl;
            testNumber++;
        }
        return times;
    }

    void SetArgs(std::vector<int> args) {
        testArgs = std::move(args);
    }

private:
    bool RunTest(std::string &infile,
                 std::string &outfile) {
        try {
            auto inputData = readFile(infile);
            auto outputData = readFile(outfile);
            T task;
            std::vector<std::string> actual = task.Run(inputData, testArgs);
            assert(actual.size() == outputData.size());
            return processResults(inputData, outputData, actual);
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
            return false;
        }
    }

private:
    std::vector<std::string> readFile(std::string &filename) {
        std::string line;
        std::vector<std::string> data;
        std::ifstream file(filename);
        while (std::getline(file, line)) {
            line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
            line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
            data.push_back(line);
        }
        return data;
    }

    std::string vectorToString(std::vector<std::string> &data) {
        std::stringstream result;
        for (const auto &value: data) {
            result << value << " ";
        }
        return result.str();
    }

    bool isNumber(const std::string &s) {
        char *end = nullptr;
        [[maybe_unused]] double val = strtod(s.c_str(), &end);
        return end != s.c_str() && *end == '\0';
    }

    bool processResults(std::vector<std::string> &inputData,
                        std::vector<std::string> &outputData,
                        std::vector<std::string> &actual) {
        if (_verbose) {
            std::cout << "Input:\t\t" << vectorToString(inputData) << std::endl;
            std::cout << "Expected:\t" << vectorToString(outputData) << std::endl;
            std::cout << "Actual:\t\t" << vectorToString(actual) << std::endl;
        }
        bool result = true;
        for (int i = 0; i < actual.size(); ++i) {
            if (_tolerance > 0 && isNumber(actual.at(i)) && isNumber(outputData.at(i))) {
                long double expectedValue = std::strtod(outputData.at(i).c_str(), nullptr);
                long double actualValue = std::strtod(actual.at(i).c_str(), nullptr);
                result &= std::abs(expectedValue - actualValue) < _tolerance;
            } else {
                result &= actual.at(i) == outputData.at(i);
            }
        }
        if (_assertOnError) {
            assert(result == true);
        }
        return result;
    }

    bool _verbose = false;
    bool _assertOnError = false;
    double _tolerance = 0;
    std::vector<int> testArgs = {};
};

class Table {
public:
    // setHeader({"1","10"})
    void setHeader(std::vector<std::string> values) {
        std::vector<std::string> header = {" "};
        std::for_each(values.begin(), values.end(), [&](std::string n) {
            header.push_back(n);
        });
        rows.push_back(header);
        std::vector<std::string> secondRow;
        for (int i = 0; i < header.size(); ++i) {
            secondRow.push_back(":---:");
        }
        rows.push_back(secondRow);
    }

    void addRow(std::string rowName, std::vector<std::string> values) {
        std::vector<std::string> row = {rowName};
        std::for_each(values.begin(), values.end(), [&](std::string n) {
            row.push_back(n);
        });
        rows.push_back(row);
    }

    void print() {
        for (int i = 0; i < rows.size(); ++i) {
            std::cout << "|";
            auto row = rows[i];
            for (int j = 0; j < row.size(); ++j) {
                std::cout << row[j] << "|";
            }
            std::cout << "\n";
        }
    }

private:
    std::vector<std::vector<std::string>> rows;
};