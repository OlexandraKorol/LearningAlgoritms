#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <utility> 

using namespace std;

// Task 1
int interpolationSearch(vector<int>& arr, int target) {
  int low = 0;
  int high = arr.size() - 1;
  
  while(target >= arr[low] && target <= arr[high]) {
      int pos = low + (double)(target - arr[low]) / (arr[high] - arr[low]) * (high - low);
        if (target == arr[pos]) {
           return pos;  
        };
    
        if (target < arr[pos]) {
            high -= pos - 1;
        } else {
            low += pos + 1;
        };
    };
    
    return -1;
};

// Task 2
void shellSortKnuth(vector<int>& arr) {
    int n = arr.size();
    vector<int> gaps;

    int gap = 1;

    while (gap < n / 3) {
        gaps.push_back(gap);
        gap = gap * 3 + 1;
    }

    gaps.push_back(gap);


    for (int g = gaps.size() - 1; g >= 0; g--) {

        gap = gaps[g];

        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}






    