#include "tester.h"
#include "selectionsort.h"
#include "insertionsort.h"
#include "heapsort.h"
#include "shellsort.h"

int main() {
    bool verbose = false;
    bool assertOnError = false;
    {
        std::cout << "==== Insertion ====" << std::endl;
        Table InsertionTable;
        Tester<InsertionSort> InsertionSortTester;
        InsertionTable.setHeader({"1", "10", "100", "1 000", "10 000", "100 000", "1 000 000"});
        InsertionTable.addRow("random",
                              InsertionSortTester.RunTests("../tests/0.random", verbose, assertOnError));
        InsertionTable.addRow("digits",
                              InsertionSortTester.RunTests("../tests/1.digits", verbose, assertOnError));
        InsertionTable.addRow("sorted",
                              InsertionSortTester.RunTests("../tests/2.sorted", verbose, assertOnError));
        InsertionTable.addRow("revers",
                              InsertionSortTester.RunTests("../tests/3.revers", verbose, assertOnError));
        InsertionTable.print();
    }
    {
        std::cout << "==== Selection ====" << std::endl;
        Table SelectionTable;
        Tester<SelectionSort> SelectionSortTester;
        SelectionTable.setHeader({"1", "10", "100", "1 000", "10 000", "100 000", "1 000 000"});
        SelectionTable.addRow("random",
                              SelectionSortTester.RunTests("../tests/0.random", verbose, assertOnError));
        SelectionTable.addRow("digits",
                              SelectionSortTester.RunTests("../tests/1.digits", verbose, assertOnError));
        SelectionTable.addRow("sorted",
                              SelectionSortTester.RunTests("../tests/2.sorted", verbose, assertOnError));
        SelectionTable.addRow("revers",
                              SelectionSortTester.RunTests("../tests/3.revers", verbose, assertOnError));
        SelectionTable.print();
    }
    {
        std::cout << "==== Shell (N/2) ====" << std::endl;
        Table ShellTable;
        Tester<ShellSort> ShellSortTester;
        ShellSortTester.SetArgs({2});
        ShellTable.setHeader({"1", "10", "100", "1 000", "10 000", "100 000", "1 000 000"});
        ShellTable.addRow("random",
                          ShellSortTester.RunTests("../tests/0.random", verbose, assertOnError));
        ShellTable.addRow("digits",
                          ShellSortTester.RunTests("../tests/1.digits", verbose, assertOnError));
        ShellTable.addRow("sorted",
                          ShellSortTester.RunTests("../tests/2.sorted", verbose, assertOnError));
        ShellTable.addRow("revers",
                          ShellSortTester.RunTests("../tests/3.revers", verbose, assertOnError));
        ShellTable.print();
    }
    {
        std::cout << "==== Shell (N/5) ====" << std::endl;
        Table ShellTable;
        Tester<ShellSort> ShellSortTester;
        ShellSortTester.SetArgs({5});
        ShellTable.setHeader({"1", "10", "100", "1 000", "10 000", "100 000", "1 000 000"});
        ShellTable.addRow("random",
                          ShellSortTester.RunTests("../tests/0.random", verbose, assertOnError));
        ShellTable.addRow("digits",
                          ShellSortTester.RunTests("../tests/1.digits", verbose, assertOnError));
        ShellTable.addRow("sorted",
                          ShellSortTester.RunTests("../tests/2.sorted", verbose, assertOnError));
        ShellTable.addRow("revers",
                          ShellSortTester.RunTests("../tests/3.revers", verbose, assertOnError));
        ShellTable.print();
    }
    {
        std::cout << "==== Shell (N/10) ====" << std::endl;
        Table ShellTable;
        Tester<ShellSort> ShellSortTester;
        ShellSortTester.SetArgs({10});
        ShellTable.setHeader({"1", "10", "100", "1 000", "10 000", "100 000", "1 000 000"});
        ShellTable.addRow("random",
                          ShellSortTester.RunTests("../tests/0.random", verbose, assertOnError));
        ShellTable.addRow("digits",
                          ShellSortTester.RunTests("../tests/1.digits", verbose, assertOnError));
        ShellTable.addRow("sorted",
                          ShellSortTester.RunTests("../tests/2.sorted", verbose, assertOnError));
        ShellTable.addRow("revers",
                          ShellSortTester.RunTests("../tests/3.revers", verbose, assertOnError));
        ShellTable.print();
    }
    {
        std::cout << "==== Heap ====" << std::endl;
        Table HeapTable;
        Tester<HeapSort> HeapSortTester;
        HeapTable.setHeader({"1", "10", "100", "1 000", "10 000", "100 000", "1 000 000"});
        HeapTable.addRow("random",
                         HeapSortTester.RunTests("../tests/0.random", verbose, assertOnError));
        HeapTable.addRow("digits",
                         HeapSortTester.RunTests("../tests/1.digits", verbose, assertOnError));
        HeapTable.addRow("sorted",
                         HeapSortTester.RunTests("../tests/2.sorted", verbose, assertOnError));
        HeapTable.addRow("revers",
                         HeapSortTester.RunTests("../tests/3.revers", verbose, assertOnError));
        HeapTable.print();
    }
    return 0;
}