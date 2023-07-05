#include <iostream>
#include <chrono>
#include "functions.h"

int main() {
    std::vector<unsigned int> N = {100000, 10000000, 1000000000};
    for (unsigned int i = 0; i < N.size(); i++) {
        std::vector<int> numbersMerge = generateRandomNumbers(N[i]);
        std::vector<int> numbersQuick = numbersMerge;
        std::vector<int> numbersBubble = numbersMerge;

        std::cout << std::endl;
        std::cout << "N = " << N[i] << std::endl;
        std::cout << std::endl;
        
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<int> auxVec(numbersMerge.size());
        mergeSort(numbersMerge, auxVec, 0, numbersMerge.size() - 1);
        auto end = std::chrono::high_resolution_clock::now();

        std::cout << "Merge Sort Time: "
                << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                << " ms" << std::endl;
        std::cout << std::endl;

        start = std::chrono::high_resolution_clock::now();
        quickSort(numbersQuick, 0, numbersQuick.size() - 1);
        end = std::chrono::high_resolution_clock::now();

        std::cout << "Quick Sort Time: "
                << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                << " ms" << std::endl;
        std::cout << std::endl;
        
        start = std::chrono::high_resolution_clock::now();
        bubbleSort(numbersBubble);
        end = std::chrono::high_resolution_clock::now();

        std::cout << "Bubble Sort Time: "
                << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                << " ms" << std::endl;
        std::cout << std::endl;
        
    }
    return 0;
}