#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;


int interpolationSearch(vector<int>& arr, int target);

// data
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}
    

vector<int> testArrayRandom;
vector<int> testArraySorted;

void insertionSort(vector<int>& arr);

int main() {
    for (int i {1}; i <= 10; i++) {
        testArrayRandom.push_back(rand() % 20 );
    };
    
    for (int i {1}; i <= 9; i++) {
        testArraySorted.push_back(i);
    };
    
    
     printArray(testArraySorted);
     
     interpolationSearch(testArraySorted, 8);
     
     printArray(testArraySorted);
    
    return 0;
}
