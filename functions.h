#include <vector>
#include <random>

void merge2Vecs(std::vector<float>& numbers, std::vector<float>& sortedVec, const int begin, const int mid, const int end);
void mergeSort(std::vector<float>& numbers, std::vector<float>& auxVec, const int begin, const int end);

int partition(std::vector<float>& numbers, const int begin, const int end);
void quickSort(std::vector<float>& numbers, const int begin, const int end);

void bubbleSort(std::vector<float>& numbers);

std::vector<float> generateRandomNumbers(unsigned int size);
