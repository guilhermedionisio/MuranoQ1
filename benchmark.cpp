#include <iostream>
#include <chrono>
#include <fstream>
#include "functions.h"

int main() {
    std::vector<unsigned int> N = {100000, 10000000, 1000000000};
    std::ofstream file("sort_times.csv");

    // Header Row
    file << "N,Merge Sort,Quick Sort,Bubble Sort" << std::endl;

    for (unsigned int i = 0; i < N.size(); i++) {
        std::vector<float> numbersMerge = generateRandomNumbers(N[i]);
        std::vector<float> numbersQuick = numbersMerge;
        std::vector<float> numbersBubble = numbersMerge;

        std::cout << std::endl;
        std::cout << "N = " << N[i] << std::endl;
        std::cout << std::endl;

        /* --------------------- MERGE SORT --------------------------- */

        auto start = std::chrono::high_resolution_clock::now();
        std::vector<float> auxVec(numbersMerge.size());
        mergeSort(numbersMerge, auxVec, 0, numbersMerge.size() - 1);
        auto end = std::chrono::high_resolution_clock::now();
        auto durationMerge = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        std::cout << "Merge Sort Time: " << durationMerge.count() << " ms" << std::endl;

        /* --------------------- QUICK SORT --------------------------- */

        start = std::chrono::high_resolution_clock::now();
        quickSort(numbersQuick, 0, numbersQuick.size() - 1);
        end = std::chrono::high_resolution_clock::now();
        auto durationQuick = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        std::cout << "Quick Sort Time: " << durationQuick.count() << " ms" << std::endl;

        /* --------------------- BUBBLE SORT --------------------------- */

        start = std::chrono::high_resolution_clock::now();
        bubbleSort(numbersBubble);
        end = std::chrono::high_resolution_clock::now();
        auto durationBubble = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        std::cout << "Bubble Sort Time: " << durationBubble.count() << " ms" << std::endl;

        /* --------------------- ADD TO FILE --------------------------- */

        // Column = Time duration of sorting
        // Row = Qty of numbers generated
        file << N[i] << "," << durationMerge.count() << "," << durationQuick.count() << "," << durationBubble.count() << std::endl;
    }

    file.close();
    return 0;
}