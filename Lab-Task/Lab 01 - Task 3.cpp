/*
Saeed 25-CS-005
Lab 01 - Task 3: Find the complexity.

Task Description:
Write the time complexity (O(1), O(n) or O(n²)) of each code fragment below, with one line of reason.
Then write a C++ program that runs fragment (b) and (c) for n = 5 and prints how many times the counted statement runs.

(a) int first = a[0];
    Time Complexity: O(1)
    Reason: Direct indexing into an array executes in a single step (constant time) regardless of the array size.

(b) for (int i = 0; i < n; i++)
        count++;
    Time Complexity: O(n)
    Reason: The loop executes n times linearly, so the statement count++ runs exactly n times.

(c) for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            count++;
    Time Complexity: O(n²)
    Reason: Two nested loops each running n times execute the statement count++ a total of n * n = n² times.

Expected Output:
Fragment (b), n = 5: count = 5
Fragment (c), n = 5: count = 25
*/

#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    // Fragment (b) execution
    int count_b = 0;
    for (int i = 0; i < n; i++)
    {
        count_b++;
    }
    cout << "Fragment (b), n = " << n << ": count = " << count_b << endl;

    // Fragment (c) execution
    int count_c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            count_c++;
        }
    }
    cout << "Fragment (c), n = " << n << ": count = " << count_c << endl;

    return 0;
}
