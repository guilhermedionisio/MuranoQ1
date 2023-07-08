#include "functions.h"

int main() {
    // Variables to test sorting
    std::vector<float> numbers = {5.2, 2.5, 3.7, 2.8, 5.4, 7.2, 4.5, 20.0, 20.0, 19.66};
    std::vector<float> numbersCopy1 = numbers;
    std::vector<float> numbersCopy2 = numbers;
    std::vector<float> Vec(numbers.size());

    // Variables to measure time
    std::vector<unsigned int> N = {E5, E7};
    std::vector<long> measTimes = {0, 0, 0};
    std::ofstream file("sort_times.csv");

    /* ----------------- SORT TEST -------------------------- */

    sortingTest(numbers);

    /* -------------------- MEASURE TIME ----------------------------- */

    // Header Row
    file << "N,Merge Sort,Quick Sort,Bubble Sort" << std::endl;

    // Measure time for N < 1e9
    for (unsigned int i = 0; i < N.size(); i++) {
        measTimes = measureSortTime(N[i], measTimes);
    }
    // Estimate time for N == 1e9
    estimateSortTime(E9, measTimes);

    file.close();
    return 0;
}