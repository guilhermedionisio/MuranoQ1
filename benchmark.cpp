#include <iostream>
#include "functions.h"

int main() {
    std::vector<int> numbers = {5, 2, 3, 2, 5, 7, 4, 20, 20, 19};
    std::vector<int> numbersCopy1 = numbers;
    std::vector<int> numbersCopy2 = numbers;

    std::cout << "Unsorted Vector: ";
    for (auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    mergeSort(numbers, 0, numbers.size() - 1);

    std::cout << "Merge Sort Sorted Vector: ";
    for (auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    quickSort(numbersCopy1, 0, numbersCopy1.size() - 1);

    std::cout << "Quick Sort Sorted Vector: ";
    for (auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    quickSort(numbersCopy2, 0, numbersCopy2.size() - 1);

    std::cout << "Bubble Sort Sorted Vector: ";
    for (auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}