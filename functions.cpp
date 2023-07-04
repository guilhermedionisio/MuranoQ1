#include "functions.h"

void merge2Vecs(std::vector<int>& numbers, const int begin, const int mid, const int end) {
    // Auxiliary vector to sort the halves
    const int size = end - begin + 1;
    std::vector<int> sortedVec(size);

    int beginStart = begin;
    int middleStart = mid + 1;
    int sortedIndex = 0;

    // Compare and store elements from the two sorted halves
    // until the end of one half
    while (beginStart <= mid && middleStart <= end) {
        if (numbers[beginStart] <= numbers[middleStart]) {
            sortedVec[sortedIndex++] = numbers[beginStart++];
        } else {
            sortedVec[sortedIndex++] = numbers[middleStart++];
        }
    }

    // Store the remaining elements of the other half
    while (beginStart <= mid) {
        sortedVec[sortedIndex++] = numbers[beginStart++];
    }

    while (middleStart <= end) {
        sortedVec[sortedIndex++] = numbers[middleStart++];
    }

    // Store the elements sorted in the original numbers vector
    // Offset the idx because they may not have the same size
    for (auto idx = begin; idx < end + 1; idx++) {
        numbers[idx] = sortedVec[idx - begin];
    }
}

void mergeSort(std::vector<int>& numbers, const int begin, const int end) {
    if (end > begin) {
        int mid = begin + (end - begin)/2;
        // Sort the first half of the vector recursively
        mergeSort(numbers, begin, mid);
        // Sort the second half of the vector recursively
        mergeSort(numbers, mid+1, end);
        // Merge the 2 halves with the right sort
        merge2Vecs(numbers, begin, mid, end);
    }
}

void quickSort(std::vector<int>& numbers) {
    // Implementar BubbleSort
}

void bubbleSort(std::vector<int>& numbers) {
    // Implementar BubbleSort
}