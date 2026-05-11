#include <stdio.h>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std::chrono;
using namespace std;

void shellSort(vector<int>& arr);
void taskOneResult(vector<int>& arr);
void taskTwoResult(vector<int>& arr);

void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}
    
vector<int> testArrayRandom;
vector<int> testArraySorted;

int main() {
for (int i = 0; i < 10000; i++) {
    testArrayRandom.push_back(rand() % 100);
}

for (int i = 0; i < 10000; i++) {
    testArraySorted.push_back(i);
}

//    TASK 1
   taskOneResult(testArraySorted);

// TASK 2
    
  taskTwoResult(testArrayRandom);
   
   
   
    

    return 0;
};
