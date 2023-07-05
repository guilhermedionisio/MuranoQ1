#include <iostream>
#include "functions.h"

int main() {
    std::vector<int> numbers = {5, 2, 3, 2, 7, 4, 20};
    std::vector<int> numbersCopy = numbers;

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

    quickSort(numbersCopy, 0, numbersCopy.size() - 1);

    std::cout << "Quick Sort Sorted Vector: ";
    for (auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}