#include "functions.h"

void merge2Vecs(std::vector<float>& numbers, std::vector<float>& auxVec, const int begin, const int mid, const int end) {
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

void mergeSort(std::vector<float>& numbers, std::vector<float>& auxVec, const int begin, const int end) {
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


int partition(std::vector<float>& numbers, const int begin, const int end) {

    // Suppose number in the middle as pivot initially
    int mid = begin + (end - begin)/2;
    float pivot = numbers[mid];

    int beginStart = begin;
    int endStart = end;

    // All elements greater than the pivot are moved to the right side of the pivot.
    // All elements smaller than the pivot are moved to the left side of the pivot.
    while (beginStart <= endStart) {
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

void quickSort(std::vector<float>& numbers, const int begin, const int end) {
    if (begin < end) {
        // Rearrange elements based on the pivot value
        int pivotIndex = partition(numbers, begin, end);
        // Sort sub-array with numbers smaller than pivot
        quickSort(numbers, begin, pivotIndex - 1);
        // Sort sub-array with numbers greater than pivot
        quickSort(numbers, pivotIndex, end);
    }
}

void bubbleSort(std::vector<float>& numbers) {
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

std::vector<float> generateRandomNumbers(unsigned int size) {
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_real_distribution<float> distribution(-100000.0, 100000.0);

    std::vector<float> numbers(size);
    for (unsigned int i = 0; i < size; i++) {
        numbers[i] = distribution(generator);
    }

    return numbers;
}

void sortingTest(std::vector<float> numbers) {
    std::vector<float> numbersCopy1 = numbers;
    std::vector<float> numbersCopy2 = numbers;
    std::vector<float> Vec(numbers.size());

    std::cout << "Unsorted Vector: ";
    for (auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    mergeSort(numbers, Vec, 0, numbers.size() - 1);
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

    bubbleSort(numbersCopy2);
    std::cout << "Bubble Sort Sorted Vector: ";
    for (auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

std::vector<long> measureSortTime(unsigned int N, std::vector<long> measTimes) {
    std::vector<float> numbersMerge = generateRandomNumbers(N);
    std::vector<float> numbersQuick = numbersMerge;
    std::vector<float> numbersBubble = numbersMerge;
    long mergeTime, quickTime, bubbleTime;
    std::ofstream file("sort_times.csv", std::ios::app);

    std::cout << std::endl;
    std::cout << "N = " << N << std::endl;
    std::cout << std::endl;

    /* --------------------- MERGE SORT --------------------------- */

    mergeTime = measureMergeTime(numbersMerge);

    /* --------------------- QUICK SORT --------------------------- */

    quickTime = measureQuickTime(numbersQuick);

    /* --------------------- BUBBLE SORT --------------------------- */
        

    // Estimate time for bubble sort after N=1e5
    if (N == E5){
        bubbleTime = measureBubbleTime(numbersBubble);
    }
    else {
        bubbleTime = estimateBubbleSortTime(measTimes[2]);
    }

    /* --------------------- ADD TO FILE --------------------------- */

    // Column = Time duration of sorting
    // Row = Qty of numbers generated
    file << N << "," << mergeTime << "," << quickTime << "," << bubbleTime << std::endl;
    return {mergeTime, quickTime, bubbleTime};
}

long measureMergeTime(std::vector<float> numbers) {

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<float> auxVec(numbers.size());
    mergeSort(numbers, auxVec, 0, numbers.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    auto durationMerge = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    long mergeTime = durationMerge.count();
    std::cout << "Merge Sort Time: " << mergeTime << " ms" << std::endl;
    return mergeTime;
}

long measureQuickTime(std::vector<float> numbers) {

    auto start = std::chrono::high_resolution_clock::now();
    quickSort(numbers, 0, numbers.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    auto durationQuick = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    long quickTime = durationQuick.count();
    std::cout << "Quick Sort Time: " << durationQuick.count() << " ms" << std::endl;
    
    return quickTime;
}

long measureBubbleTime(std::vector<float> numbers) {

    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(numbers);
    auto end = std::chrono::high_resolution_clock::now();
    auto durationBubble = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    long bubbleTime = durationBubble.count();
    std::cout << "Bubble Sort Time: " << bubbleTime << " ms" << std::endl;
    
    return bubbleTime;
}

void estimateSortTime(unsigned int N, std::vector<long> lastMeasuredTimes) {
    std::ofstream file("sort_times.csv", std::ios::app);

    std::cout << std::endl;
    std::cout << "N = " << N << std::endl;
    std::cout << std::endl;
    
    long estMergeSortTime = estimateMergeSortTime(lastMeasuredTimes[0]);
    long estQuickSortTime = estimateQuickSortTime(lastMeasuredTimes[1]);
    long estBubbleSortTime = estimateBubbleSortTime(lastMeasuredTimes[2]);

    file << N << "," << estMergeSortTime << "," << estQuickSortTime << "," << estBubbleSortTime << std::endl;

}

long estimateMergeSortTime(long lastMeasuredTime) {
    // EstimatedTime = lastMeasuredTime * N*log2(N) / (oldN*log2(oldN)) = lastMeasuredTime * 130
    long estTime;
    estTime = lastMeasuredTime * 100 * 1.3;
    std::cout << "Merge Sort Time: " << estTime << " ms" << std::endl;
    return estTime;
}

long estimateQuickSortTime(long lastMeasuredTime) {
    // EstimatedTime = lastMeasuredTime * N*log2(N) / (oldN*log2(oldN)) = lastMeasuredTime * 130
    long estTime;
    estTime = lastMeasuredTime * 130;
    std::cout << "Quick Sort Time: " << estTime << " ms" << std::endl;
    return estTime;
}

long estimateBubbleSortTime( long lastMeasuredTime) {
    // EstimatedTime = lastMeasuredTime * N^2 / oldN^2 = lastMeasuredTime * 10^4
    long estTime;
    estTime = lastMeasuredTime * 100 * 100;
    std::cout << "Bubble Sort Time: " << estTime << " ms" << std::endl;
    return estTime;
}