#include <stdio.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std::chrono;
using namespace std;

int interpolationSearch(vector<int>& arr, int target);
int binarySearch(const vector<int>& arr, int target);
void shellSort(vector<int>& arr);
void shellSortKnuth(vector<int>& arr);

void taskOneResult(vector<int>& arr) {
    for (int i = 0; i <= 100000; i += 10) {
        arr.push_back(i);
    };

    int target = 80000;

    auto start1 = high_resolution_clock::now();
    for (int i = 0; i < 100000; i++) {
        interpolationSearch(arr, target);
    };
    auto stop1 = high_resolution_clock::now();


    auto start2 = high_resolution_clock::now();
    for (int i = 0; i < 100000; i++) {
        binarySearch(arr, target);
    };
    auto stop2 = high_resolution_clock::now();


    auto time1 = duration_cast<nanoseconds>(stop1 - start1);
    auto time2 = duration_cast<nanoseconds>(stop2 - start2);

    cout << "Interpolation: " << time1.count() << " ns" << endl;
    cout << "Binary: " << time2.count() << " ns" << endl;    
};


void taskTwoResult (vector<int>& arr) {
    srand(time(0));

    for (int i = 0; i < 10000; i++) {
        arr.push_back(rand() % 100000);
    }

    vector<int> arrClassic = arr;
    vector<int> arrKnuth = arr;

    auto start1 = high_resolution_clock::now();

    shellSort(arrClassic);

    auto stop1 = high_resolution_clock::now();

   
    auto start2 = high_resolution_clock::now();

    shellSortKnuth(arrKnuth);

    auto stop2 = high_resolution_clock::now();

    auto time1 = duration_cast<microseconds>(stop1 - start1);
    auto time2 = duration_cast<microseconds>(stop2 - start2);

    cout << "Classic  Sort: " << time1.count() << " ms" << endl;
    cout << "Knuth  Sort: " << time2.count() << " ms" << endl;
}
