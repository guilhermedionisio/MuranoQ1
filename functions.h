#include <vector>
#include <random>
#include <iostream>
#include <fstream>
#include <chrono>

#define E5      100000
#define E7      10000000
#define E9      1000000000

void merge2Vecs(std::vector<float>& numbers, std::vector<float>& sortedVec, const int begin, const int mid, const int end);
void mergeSort(std::vector<float>& numbers, std::vector<float>& auxVec, const int begin, const int end);

int partition(std::vector<float>& numbers, const int begin, const int end);
void quickSort(std::vector<float>& numbers, const int begin, const int end);

void bubbleSort(std::vector<float>& numbers);

std::vector<float> generateRandomNumbers(unsigned int size);

void sortingTest(std::vector<float> numbers);

std::vector<long> measureSortTime(unsigned int N, std::vector<long> measTimes);
long measureMergeTime(std::vector<float> numbers);
long measureQuickTime(std::vector<float> numbers);
long measureBubbleTime(std::vector<float> numbers);

void estimateSortTime(unsigned int N, std::vector<long> lastMeasuredTimes);
long estimateMergeSortTime(long lastMeasuredTime);
long estimateQuickSortTime(long lastMeasuredTime);
long estimateBubbleSortTime(long lastMeasuredTime);


