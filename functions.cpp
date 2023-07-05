#include "functions.h"

void merge2Vecs(std::vector<int>& numbers, std::vector<int>& auxVec, const int begin, const int mid, const int end) {
    int beginStart = begin;
    int middleStart = mid + 1;
    int sortedIndex = 0;

    // Compare and store elements from the two sorted halves
    // until the end of one half
    while (beginStart <= mid && middleStart <= end) {
        if (numbers[beginStart] <= numbers[middleStart]) {
            auxVec[sortedIndex++] = numbers[beginStart++];
        } else {
            auxVec[sortedIndex++] = numbers[middleStart++];
        }
    }

    // Store the remaining elements of the other half
    while (beginStart <= mid)
        auxVec[sortedIndex++] = numbers[beginStart++];

    while (middleStart <= end)
        auxVec[sortedIndex++] = numbers[middleStart++];

    // Store the elements sorted in the original numbers vector
    // Offset the idx because they may not have the same size
    for (int i = 0; i < sortedIndex; i++)
        numbers[begin + i] = auxVec[i];
}

void mergeSort(std::vector<int>& numbers, std::vector<int>& auxVec, const int begin, const int end) {
    if (end > begin) {
        int mid = begin + (end - begin)/2;
        // Sort the first half of the vector recursively
        mergeSort(numbers, auxVec, begin, mid);
        // Sort the second half of the vector recursively
        mergeSort(numbers, auxVec, mid+1, end);
        // Merge the 2 halves with the right sort
        merge2Vecs(numbers, auxVec, begin, mid, end);
    }
}


int partition(std::vector<int>& numbers, const int begin, const int end) {

    // Suppose number in the middle as pivot initially
    int mid = begin + (end - begin)/2;
    int pivot = numbers[mid];

    int beginStart = begin;
    int endStart = end;

    // All elements greater than the pivot are moved to the right side of the pivot.
    // All elements smaller than the pivot are moved to the left side of the pivot.
    while (beginStart < endStart) {
        // Check if there's number on the left of pivot to swap
        while (numbers[beginStart] < pivot)
            beginStart++;
        // Check if there's number on the right of pivot to swap
        while (numbers[endStart] > pivot)
            endStart--;
        // If there is a pair on different halves to swap
        // Do the swap
        if (beginStart <= endStart)
            std::swap(numbers[beginStart++], numbers[endStart--]);
    }

    // Return the new pivot index after partition
    return beginStart;
}

void quickSort(std::vector<int>& numbers, const int begin, const int end) {
    if (begin < end) {
        // Rearrange elements based on the pivot value
        int pivotIndex = partition(numbers, begin, end);
        // Sort sub-array with numbers smaller than pivot
        quickSort(numbers, begin, pivotIndex - 1);
        // Sort sub-array with numbers greater than pivot
        quickSort(numbers, pivotIndex, end);
    }
}

void bubbleSort(std::vector<int>& numbers) {
    bool swapped;
    // Compare each number with all the others after it
    for (unsigned int i = 0; i < numbers.size() - 1; i++) {
        swapped = false;
        for (unsigned int j = 0; j < numbers.size() - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                std::swap(numbers[j], numbers[j + 1]);
                swapped = true;
            }
        }
        // If a round of comparison makes no swaps,
        // whole vector is already sorted
        if (!swapped)
            break;
    }
}

std::vector<int> generateRandomNumbers(unsigned int size) {
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(-100000, 100000);

    std::vector<int> numbers(size);
    for (unsigned int i = 0; i < size; i++) {
        numbers[i] = distribution(generator);
    }

    return numbers;
}