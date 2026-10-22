/*//! Build the Exam Roll Number Sorter.
Write the whole program yourself, one function at a time:

display, copyArray, quickSort, merge, mergeSort

In main, start from {120, 105, 150, 101, 130}, call copyArray before every algorithm, and finish with a binary search for 130 on the sorted array. Your output must match this:

After Quick Sort:
Students: 101 105 120 130 150

After Merge Sort:
Students: 101 105 120 130 150
*/

#include <iostream>
using namespace std;


void display(int students[], int n) {
    cout << "Students: ";
    for (int i = 0; i < n; i++)
    cout << students[i] << " ";
    cout << endl;
}

void copyArray(int from[], int to[], int n)
{
    for (int i = 0; i < n; i++)
    to[i] = from[i];
}


int partition(int students[], int low, int high)
{
    int pivot = students[high]; // last element is the pivot
    int i = low - 1; // end of the "smaller" area
    for (int j = low; j < high; j++)
    { // j scans the array
        if (students[j] < pivot)
        {
            i++; // the smaller area grows
            int temp = students[i];
            students[i] = students[j];
            students[j] = temp;
        }
    }
    int temp = students[i + 1]; // put the pivot after the smaller area
    students[i + 1] = students[high];
    students[high] = temp;
    return i + 1; // final index of the pivot
}


void quickSort(int students[], int low, int high)
{
    if (low < high)
    { // at least 2 elements
        int pivotIndex = partition(students, low, high);
        quickSort(students, low, pivotIndex - 1); // sort the left part
        quickSort(students, pivotIndex + 1, high); // sort the right part
    }
}



void merge(int students[], int low, int mid, int high)
{
    int temp[MAX_SIZE]; // helper array
    int i = low; // front of the left half
    int j = mid + 1; // front of the right half
    int k = low; // next free place in temp

    while (i <= mid && j <= high)
    { // both halves still have elements
        if (students[i] <= students[j])
        temp[k++] = students[i++];
        else
        temp[k++] = students[j++];
    }

    while (i <= mid) temp[k++] = students[i++]; // rest of the left half
    while (j <= high) temp[k++] = students[j++]; // rest of the right half
    for (int x = low; x <= high; x++) // copy the result back
    students[x] = temp[x];
}


void mergeSort(int students[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2; // middle index
        mergeSort(students, low, mid); // sort the left half
        mergeSort(students, mid + 1, high); // sort the right half
        merge(students, low, mid, high); // join the sorted halves
    }
}




int main()
{
    const int MAX_SIZE = 100;
    int students[MAX_SIZE] = {120, 105, 150, 101, 130};
    int n = 5;

    quickSort(students, 0, n - 1);
    mergeSort(students, 0, n - 1);
}
