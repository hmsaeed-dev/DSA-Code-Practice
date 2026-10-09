/* Sum of first n numbers. Write a program that takes n from the user and prints the sum 1 + 2 + ... + n using a loop.

Write the time complexity as a comment.
Enter n: 5
Sum = 15
*/

#include <iostream>
using namespace std;

int main()
{
    int num, sum=0;
    cout << "Enter a number" << endl;
    cin >> num;

    for(int i=1; i<=num; i++)
    {
        sum = sum + i; // Time complexiy O(n)
    }
    cout << "Sum : " << sum;
}

