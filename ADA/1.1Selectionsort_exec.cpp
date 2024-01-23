//Selection sort and its execution time

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform selection sort on a vector
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Function to measure the execution time of a given function
template <typename Func>
double measureExecutionTime(Func func) {
    time_t start, end;

    // Record start time
    time(&start);

    // Execute the function
    func();

    // Record end time
    time(&end);

    // Calculate total time taken by the program
    double time_taken = difftime(end, start);

    return time_taken;
}

int main() {
    // Varying array sizes from 10000 to 100000 with a gap of 10000
    for (int size = 10000; size <= 100000; size += 10000) {
        // Create a vector with random values
        vector<int> arr(size);
        for (int& num : arr) {
            num = rand() % 1000;  // Generating random numbers for simplicity
        }

        // Measure the execution time of selection sort for the current array size
        double executionTime = measureExecutionTime([&]() {
            selectionSort(arr);
        });

        cout << "Execution time for array size " << size << ": " << fixed << executionTime << " seconds" << endl;
    }

    return 0;
}
