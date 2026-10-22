/*
Saeed 25-CS-005
Lab 02 - Task 3: Measure the work.

Task Description:
Measure the work. Complexity is a claim about how the work grows, so test it. Add a counter to
the functions: count the shifts made by insertAtBeginning and the comparisons made by
linearSearch and binarySearch. Fill the array with the sorted values 1, 2, 3, ... n for n = 10,
100 and 1000. For each n, insert at the beginning (worst case for insertion), then search for the last
element with both searches. Record your counts in a table like this one:
n Shifts: insert at beginning Linear search comparisons Binary search steps
10
100
1000

Answers:
(a) When n becomes 10 times bigger:
    - Shifts made by insertAtBeginning increase by 10x (linear growth).
    - Linear search comparisons increase by ~10x (linear growth).
    - Binary search steps increase by only ~3-4 steps (logarithmic growth).
(b) Shifts and linear search comparisons match O(n); binary search steps match O(log n).
(c) Constant time O(1) for end operations is possible because arrays store elements contiguously
    and support direct indexing. Accessing index n or n - 1 requires no shifting.
*/

#include <iostream>
using namespace std;

int insertAtBeginning(int arr[], int &n, int val) {
    int shifts = 0;
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
        shifts++;
    }
    arr[0] = val;
    n++;
    return shifts;
}

int linearSearch(const int arr[], int n, int key) {
    int comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == key) {
            return comparisons;
        }
    }
    return comparisons;
}

int binarySearch(const int arr[], int n, int key) {
    int steps = 0;
    int low = 0, high = n - 1;
    while (low <= high) {
        steps++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return steps;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return steps;
}

int main() {
    int test_sizes[] = {10, 100, 1000};
    int arr[2000];

    cout << "n\tShifts: insert at beginning\tLinear search comparisons\tBinary search steps" << endl;

    for (int t = 0; t < 3; t++) {
        int n = test_sizes[t];

        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }

        int target = n;
        int shifts = insertAtBeginning(arr, n, 0);
        int linear_comps = linearSearch(arr, n, target);
        int binary_steps = binarySearch(arr, n, target);

        cout << test_sizes[t] << "\t" << shifts << "\t\t\t\t" << linear_comps << "\t\t\t\t" << binary_steps << endl;
    }

    return 0;
}
