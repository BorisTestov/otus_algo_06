#include "tester.h"
#include "selectionsort.h"
#include "insertionsort.h"
#include "heapsort.h"
#include "shellsort.h"

int main() {
    ITaskPtr InsertionSortTask = std::make_unique<InsertionSort>();
    Tester InsertionSortTester(InsertionSortTask, "../tests/0.random");
    InsertionSortTester.RunTests(false, false);
    return 0;
}
