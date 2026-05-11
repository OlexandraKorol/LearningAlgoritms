#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


int binarySearch(const vector<int>& arr, int target) {
  int left = 0;
  int right = arr.size() - 1;
  
  while (left <= right) {
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
      return mid;
    };
    
    if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    };
  };
    return -1;
};


void shellSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int gap {n / 2}; gap > 0; gap /= 2){
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            };
                arr[j] = temp;
        };
    };
};


int partition(vector<int>& arr, int low, int high){
    
}