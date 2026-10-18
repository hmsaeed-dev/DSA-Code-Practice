//! Reverse an Array
// Time complexity O(n)

#include <iostream>
using namespace std;

void reverse_arr(int arr[], int size)
{
    // 2 pointer approach
    int start = 0;
    int end = size -1;

    // for even or odd array {{start < end}}
    while(start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    int size;
    cout << "Enter size of array (>0) : \n";
    cin >> size;

    int arr[size];
    cout << "Enter elements of array : \n";
    for(int i=0; i<size; i++)
    {
        cin >> arr[i];
    }

    reverse_arr(arr, size);
    cout << "Reverse array : \n";
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << endl;
    }
}
