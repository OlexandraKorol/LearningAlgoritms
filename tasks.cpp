#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <utility> 

using namespace std;

int partition(vector<int>& arr, int low, int high);
void insertionSortRange(vector<int>& arr, int left, int right);
void quickSort(vector<int>& arr, int low, int high);

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

// Task 3


pair<int, int> dutchFlagPartitioning(vector<int>& lst, int startIndex, int lastIndex, int pivot_value) {
    int lt = startIndex;
    int gt = lastIndex;
    int eq = startIndex;

    while (eq <= gt) {

        if (lst[eq] == pivot_value) {
            eq += 1;

        } else if (lst[eq] > pivot_value) {
            swap(lst[gt], lst[eq]);
            gt -= 1;

        } else if (lst[eq] < pivot_value) {
            swap(lst[lt], lst[eq]);
            lt += 1;
            eq += 1;
        }
    }

    return {lt - 1, gt + 1};
}

void dutchFlagQuickSort(vector<int>& lst, int start_index, int end_index) {

    if (start_index >= end_index) {
        return;
    }

    int pivot_index = start_index + rand() % (end_index - start_index + 1);
    int pivot_value = lst[pivot_index];

    pair<int, int> borders =
        dutchFlagPartitioning(lst, start_index, end_index, pivot_value);

    int left = borders.first;
    int right = borders.second;

    dutchFlagQuickSort(lst, start_index, left);
    dutchFlagQuickSort(lst, right, end_index);
}



// Task 4 

void combinedSort(vector<int>& arr, int left, int right, int thereshold) {
    if (right - left + 1 <= thereshold) {
        insertionSortRange(arr, left, right);
        return;
    }

    int pivot = partition(arr, left, right);

    quickSort(arr, left, pivot - 1);
    quickSort(arr, pivot + 1, right);
};