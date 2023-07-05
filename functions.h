#include <vector>
#include <random>

void merge2Vecs(std::vector<int>& numbers, std::vector<int>& sortedVec, const int begin, const int mid, const int end);
void mergeSort(std::vector<int>& numbers, std::vector<int>& auxVec, const int begin, const int end);

int partition(std::vector<int>& numbers, const int begin, const int end);
void quickSort(std::vector<int>& numbers, const int begin, const int end);

void bubbleSort(std::vector<int>& numbers);

std::vector<int> generateRandomNumbers(unsigned int size);
