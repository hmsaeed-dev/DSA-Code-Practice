/*
    Saeed 25-CS-005
    !!Largest element.
Write a program that reads 5 integers into an array and prints the largest one.
Enter 5 numbers: 4 9 2 7 5
Largest = 9
*/

#include <iostream>
using namespace std;

int main()
{
    int largest = 0;
    int num[5];
    cout << "Enter the numbers one by one" << endl;

    for(int i=0; i<5; i++)
    {
        cin >> num[i];
        if(largest<num[i]){largest = num[i];}
    }
    cout << "Largest : " << largest << endl;

}
