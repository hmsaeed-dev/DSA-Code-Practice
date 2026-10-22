/*
Saeed 25-CS-005
Lab 02 - Task 2: Course enrolment with a waiting rule.

Task Description:
A course keeps its roll numbers in a sorted array (capacity 10). Write enrol(roll) and drop(roll)
that always keep the array sorted:
- enrol must use binary search to reject a roll number that is already enrolled, then find the correct
  position with a loop and insert there.
- drop must use binary search to find the student and then delete with shifting.
- Print a clear message for every rejected request (duplicate, not found, course full).
- Test with the sequence below, then explain in a comment why you can use binary search in both functions.

Expected Output:
enrol(110) -> Students: 110
enrol(105) -> Students: 105 110
enrol(120) -> Students: 105 110 120
enrol(110) -> Roll number 110 is already enrolled
enrol(115) -> Students: 105 110 115 120
drop(105) -> Students: 110 115 120
drop(999) -> Roll number 999 not found
*/

#include <iostream>
using namespace std;

const int CAPACITY = 10;
int students[CAPACITY];
int n = 0;

// Time Complexity: O(log n)
// Space Complexity: O(1)
int binarySearch(const int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
void display(const int arr[], int size) {
    cout << "Students:";
    for (int i = 0; i < size; i++) {
        cout << " " << arr[i];
    }
    cout << endl;
}

// enrol: rejects duplicates using binarySearch, finds sorted position with a loop, and inserts with shifting
// Time Complexity: O(n) due to shifting, O(log n) search
// Space Complexity: O(1)
void enrol(int roll) {
    cout << "enrol(" << roll << ") -> ";

    // 1. Check if course is full
    if (n >= CAPACITY) {
        cout << "Course is full. Cannot enrol " << roll << endl;
        return;
    }

    // 2. Reject duplicate using binary search
    if (binarySearch(students, n, roll) != -1) {
        cout << "Roll number " << roll << " is already enrolled" << endl;
        return;
    }

    // 3. Find correct position to maintain sorted order
    int pos = 0;
    while (pos < n && students[pos] < roll) {
        pos++;
    }

    // 4. Shift elements right from pos to make room
    for (int i = n; i > pos; i--) {
        students[i] = students[i - 1];
    }

    // 5. Insert new student and increment size
    students[pos] = roll;
    n++;

    // 6. Display current students list
    display(students, n);
}

// drop: finds student using binarySearch, then deletes with left-shifting
// Time Complexity: O(n) due to shifting, O(log n) search
// Space Complexity: O(1)
void drop(int roll) {
    cout << "drop(" << roll << ") -> ";

    // 1. Check if course is empty
    if (n <= 0) {
        cout << "Course is empty. Cannot drop " << roll << endl;
        return;
    }

    // 2. Find student using binary search
    int pos = binarySearch(students, n, roll);
    if (pos == -1) {
        cout << "Roll number " << roll << " not found" << endl;
        return;
    }

    // 3. Delete student by shifting elements left
    for (int i = pos; i < n - 1; i++) {
        students[i] = students[i + 1];
    }
    n--;

    // 4. Display current students list
    display(students, n);
}

int main() {
    enrol(110);
    enrol(105);
    enrol(120);
    enrol(110);
    enrol(115);
    drop(105);
    drop(999);

    return 0;
}

/*
Explanation: Why we can use binary search in both functions
-----------------------------------------------------------
Binary search requires the precondition that the elements in the array are always maintained in sorted order.
1. In enrol(roll): Every insertion first locates the correct index using a comparison loop (students[pos] < roll)
   and shifts subsequent elements right. Thus, the array remains strictly sorted in ascending order after every enrollment.
2. In drop(roll): Deletion removes an element and shifts all subsequent elements one position left to fill the gap,
   which preserves the relative sorted order of all remaining elements.
Because the sorted invariant is preserved throughout the entire lifecycle of the array, binary search is always valid,
correct, and optimal (O(log n)) to use for both checking duplicates in enrol and locating elements to remove in drop.
*/
