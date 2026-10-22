/* //! Student Record System.
Saeed 25-CS-005
Lab 02 - Task 1: Build the Student Record System.

Write the whole program yourself, one function at a time, using the problem of this manual:
display, insertAtEnd, insertAtBeginning, insertAtPosition, linearSearch, binarySearch,
deleteFromEnd, deleteFromBeginning and deleteFromPosition.
Every function must reject a full array, an empty array or a bad position with a message.
In main, follow the story of Section 1 starting from {101, 105, 110, 115, 120}, show the array
after every change, and delete student 108 by searching for it first. Your output must match this:

Initial register:
Students: 101 105 110 115 120
After inserting 125 at the end:
Students: 101 105 110 115 120 125
After inserting 95 at the beginning:
Students: 95 101 105 110 115 120 125
After inserting 108 at index 3:
Students: 95 101 105 108 110 115 120 125
Linear search for 115: found at index 5
Binary search for 115: found at index 5
Linear search for 100: not found
Binary search for 100: not found
After deleting from the end:
Students: 95 101 105 108 110 115 120
After deleting from the beginning:
Students: 101 105 108 110 115 120
After deleting student 108 (found at index 2):
Students: 101 105 110 115 120
*/

#include <iostream>
using namespace std;

// Time Complexity: O(n) - traverses through all n elements to print them
// Space Complexity: O(1)
void display(const int students[], int n) {
    if (n <= 0) {
        cout << "Array is empty." << endl;
        return;
    }
    cout << "Students: ";
    for (int i = 0; i < n; i++) {
        cout << students[i] << " ";
    }
    cout << endl;
}

// Time Complexity: O(1) - inserts directly at index n without shifting
// Space Complexity: O(1)
void insertAtEnd(int students[], int &n, int capacity, int value) {
    if (n >= capacity) {
        cout << "Error: Array is full. Cannot insert " << value << endl;
        return;
    }
    students[n] = value;
    n++;
}

// Time Complexity: O(n) - shifts all n existing elements one place to the right
// Space Complexity: O(1)
void insertAtBeginning(int students[], int &n, int capacity, int value) {
    if (n >= capacity) {
        cout << "Error: Array is full. Cannot insert " << value << endl;
        return;
    }
    for (int i = n; i > 0; i--) {
        students[i] = students[i - 1];
    }
    students[0] = value;
    n++;
}

// Time Complexity: O(n) - shifts (n - position) elements one place to the right
// Space Complexity: O(1)
void insertAtPosition(int students[], int &n, int capacity, int position, int value) {
    if (n >= capacity) {
        cout << "Error: Array is full. Cannot insert " << value << endl;
        return;
    }
    if (position < 0 || position > n) {
        cout << "Error: Invalid position " << position << ". Valid positions are 0 to " << n << endl;
        return;
    }
    for (int i = n; i > position; i--) {
        students[i] = students[i - 1];
    }
    students[position] = value;
    n++;
}

// Time Complexity: O(n) worst/average case, O(1) best case - linear scan
// Space Complexity: O(1)
int linearSearch(const int students[], int n, int key) {
    if (n <= 0) {
        cout << "Error: Array is empty." << endl;
        return -1;
    }
    for (int i = 0; i < n; i++) {
        if (students[i] == key) {
            return i;
        }
    }
    return -1;
}

// Time Complexity: O(log n) worst/average case, O(1) best case - repeatedly halves the search interval
// Space Complexity: O(1)
int binarySearch(const int students[], int n, int key) {
    if (n <= 0) {
        cout << "Error: Array is empty." << endl;
        return -1;
    }
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (students[mid] == key) {
            return mid;
        } else if (students[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Time Complexity: O(1) - simply decrements n without shifting
// Space Complexity: O(1)
void deleteFromEnd(int[], int &n) {
    if (n <= 0) {
        cout << "Error: Array is empty. Cannot delete." << endl;
        return;
    }
    n--;
}

// Time Complexity: O(n) - shifts all (n - 1) elements one place to the left
// Space Complexity: O(1)
void deleteFromBeginning(int students[], int &n) {
    if (n <= 0) {
        cout << "Error: Array is empty. Cannot delete." << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        students[i] = students[i + 1];
    }
    n--;
}

// Time Complexity: O(n) - shifts (n - 1 - position) elements one place to the left
// Space Complexity: O(1)
void deleteFromPosition(int students[], int &n, int position) {
    if (n <= 0) {
        cout << "Error: Array is empty. Cannot delete." << endl;
        return;
    }
    if (position < 0 || position >= n) {
        cout << "Error: Invalid position " << position << ". Valid positions are 0 to " << n - 1 << endl;
        return;
    }
    for (int i = position; i < n - 1; i++) {
        students[i] = students[i + 1];
    }
    n--;
}

int main()
{
    const int MAX_SIZE = 100;
    int students[MAX_SIZE] = {101, 105, 110, 115, 120};
    int n = 5;

    // Initial register
    cout << "Initial register:" << endl;
    display(students, n);

    // Insert 125 at the end
    insertAtEnd(students, n, MAX_SIZE, 125);
    cout << "After inserting 125 at the end:" << endl;
    display(students, n);

    // Insert 95 at the beginning
    insertAtBeginning(students, n, MAX_SIZE, 95);
    cout << "After inserting 95 at the beginning:" << endl;
    display(students, n);

    // Insert 108 at index 3
    insertAtPosition(students, n, MAX_SIZE, 3, 108);
    cout << "After inserting 108 at index 3:" << endl;
    display(students, n);

    // Linear search for 115
    int idx = linearSearch(students, n, 115);
    if (idx != -1)
        cout << "Linear search for 115: found at index " << idx << endl;
    else
        cout << "Linear search for 115: not found" << endl;

    // Binary search for 115
    idx = binarySearch(students, n, 115);
    if (idx != -1)
        cout << "Binary search for 115: found at index " << idx << endl;
    else
        cout << "Binary search for 115: not found" << endl;

    // Linear search for 100
    idx = linearSearch(students, n, 100);
    if (idx != -1)
        cout << "Linear search for 100: found at index " << idx << endl;
    else
        cout << "Linear search for 100: not found" << endl;

    // Binary search for 100
    idx = binarySearch(students, n, 100);
    if (idx != -1)
        cout << "Binary search for 100: found at index " << idx << endl;
    else
        cout << "Binary search for 100: not found" << endl;

    // Delete from the end
    deleteFromEnd(students, n);
    cout << "After deleting from the end:" << endl;
    display(students, n);

    // Delete from the beginning
    deleteFromBeginning(students, n);
    cout << "After deleting from the beginning:" << endl;
    display(students, n);

    // Delete student 108 by searching for it first
    int pos108 = binarySearch(students, n, 108);
    if (pos108 != -1) {
        cout << "After deleting student 108 (found at index " << pos108 << "):" << endl;
        deleteFromPosition(students, n, pos108);
        display(students, n);
    } else {
        cout << "Student 108 not found." << endl;
    }

    return 0;
}
