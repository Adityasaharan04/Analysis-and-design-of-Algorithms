//String comination generator with execution time

#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to generate all permutations of a string
void generatePermutations(const string& str) {
    string currentPermutation = str;

    cout << "Total number of permutations: " << factorial(str.length()) << endl;

    do {
        cout << currentPermutation << endl;
    } while (next_permutation(currentPermutation.begin(), currentPermutation.end()));
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
    string input;
    cout << "Enter a string to generate permutations: ";
    cin >> input;

    // Measure the execution time of generating permutations
    double executionTime = measureExecutionTime([&]() {
        generatePermutations(input);
    });

    cout << "Execution time for generating permutations: " << fixed << executionTime << " seconds" << endl;

    return 0;
}
