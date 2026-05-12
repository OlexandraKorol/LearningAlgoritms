#include <stdio.h>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std::chrono;
using namespace std;

void shellSort(vector<int>& arr);
void taskOneResult(vector<int>& arr);
void taskTwoResult(vector<int>& arr);
void dutchFlagQuickSort(vector<int>& lst, int start_index, int end_index);
void combinedSort(vector<int>& arr, int left, int right, int thereshold);


void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}
    
vector<int> testArrayRandom;
vector<int> testArraySorted;

int main() {
for (int i = 0; i < 20; i++) {
    testArrayRandom.push_back(rand() % 10);
}

for (int i = 0; i < 10000; i++) {
   testArraySorted.push_back(i);
}

// TASK 1
  taskOneResult(testArraySorted);

// TASK 2
   
 taskTwoResult(testArrayRandom);
   
// TASK 3
   cout << "Before sort: " << endl;
   printArray(testArrayRandom);
   
   dutchFlagQuickSort(testArrayRandom, 0, (testArrayRandom.size() - 1));
   
   cout << "After sort: " << endl;
   
   printArray(testArrayRandom);
    
    
// TASK 4

    cout << "Before sort: " << endl;
    printArray(testArrayRandom);
    
    combinedSort(testArrayRandom, 0, (testArrayRandom.size() - 1), 10);
    
    cout << "After sort: " << endl;
    
    printArray(testArrayRandom);



    return 0;
};
