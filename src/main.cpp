#include "tester.h"
#include "selectionsort.h"
#include "insertionsort.h"
#include "heapsort.h"
#include "shellsort.h"

int main() {
    bool verbose = false;
    bool assertOnError = false;
    std::string path;
    Tester<InsertionSort> InsertionSortTester;
    Tester<SelectionSort> SelectionSortTester;
    Tester<ShellSort> ShellSortTester;
    Tester<HeapSort> HeapSortTester;
    //
    std::cout << "==== RANDOM ====" << std::endl;
    path = "../tests/0.random";
    std::cout << "==== InsertionSort ====" << std::endl;
    InsertionSortTester.RunTests(path, verbose, assertOnError);
    std::cout << "==== SelectionSort ====" << std::endl;
    SelectionSortTester.RunTests(path, verbose, assertOnError);
    std::cout << "==== ShellSort (2) ====" << std::endl;
    ShellSortTester.SetArgs({2});
    std::cout << "==== ShellSort (5) ====" << std::endl;
    ShellSortTester.SetArgs({5});
    ShellSortTester.RunTests(path, verbose, assertOnError);
    std::cout << "==== ShellSort (10) ====" << std::endl;
    ShellSortTester.SetArgs({10});
    ShellSortTester.RunTests(path, verbose, assertOnError);
    std::cout << "==== HeapSort ====" << std::endl;
    HeapSortTester.RunTests(path, verbose, assertOnError);
    //
    std::cout << "==== DIGITS ====" << std::endl;
    path = "../tests/1.digits";
    std::cout << "==== InsertionSort ====" << std::endl;
    InsertionSortTester.RunTests(path, verbose, assertOnError);
    std::cout << "==== SelectionSort ====" << std::endl;
    SelectionSortTester.RunTests(path, verbose, assertOnError);
    std::cout << "==== ShellSort (2) ====" << std::endl;
    ShellSortTester.SetArgs({2});
    std::cout << "==== ShellSort (5) ====" << std::endl;
    ShellSortTester.SetArgs({5});
    ShellSortTester.RunTests(path, verbose, assertOnError);
    std::cout << "==== ShellSort (10) ====" << std::endl;
    ShellSortTester.SetArgs({10});
    ShellSortTester.RunTests(path, verbose, assertOnError);
    std::cout << "==== HeapSort ====" << std::endl;
    HeapSortTester.RunTests(path, verbose, assertOnError);
    //
    std::cout << "==== SORTED ====" << std::endl;
    path = "../tests/2.sorted";
    std::cout << "==== InsertionSort ====" << std::endl;
    InsertionSortTester.RunTests(path, verbose, assertOnError);
    std::cout << "==== SelectionSort ====" << std::endl;
    SelectionSortTester.RunTests(path, verbose, assertOnError);
    std::cout << "==== ShellSort (2) ====" << std::endl;
    ShellSortTester.SetArgs({2});
    std::cout << "==== ShellSort (5) ====" << std::endl;
    ShellSortTester.SetArgs({5});
    ShellSortTester.RunTests(path, verbose, assertOnError);
    std::cout << "==== ShellSort (10) ====" << std::endl;
    ShellSortTester.SetArgs({10});
    ShellSortTester.RunTests(path, verbose, assertOnError);
    std::cout << "==== HeapSort ====" << std::endl;
    HeapSortTester.RunTests(path, verbose, assertOnError);
    //
    std::cout << "==== REVERS ====" << std::endl;
    path = "../tests/3.revers";
    std::cout << "==== InsertionSort ====" << std::endl;
    InsertionSortTester.RunTests(path, verbose, assertOnError);
    std::cout << "==== SelectionSort ====" << std::endl;
    SelectionSortTester.RunTests(path, verbose, assertOnError);
    std::cout << "==== ShellSort (2) ====" << std::endl;
    ShellSortTester.SetArgs({2});
    std::cout << "==== ShellSort (5) ====" << std::endl;
    ShellSortTester.SetArgs({5});
    ShellSortTester.RunTests(path, verbose, assertOnError);
    std::cout << "==== ShellSort (10) ====" << std::endl;
    ShellSortTester.SetArgs({10});
    ShellSortTester.RunTests(path, verbose, assertOnError);
    std::cout << "==== HeapSort ====" << std::endl;
    HeapSortTester.RunTests(path, verbose, assertOnError);
    return 0;
}
