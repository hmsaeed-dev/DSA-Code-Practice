// !Linear Search in Arrays
// Time complexity O(n)

#include <iostream>
using namespace std;

int search(int array[], int size, int key)
{
    for(int i=0; i<size; i++)
    {
        if(key==array[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int array[10] = {2, 45, 5, 67, 11, 78, 33, 77, 29, 52};
    int size = 10;
    int key;
    cout << "Search element : " << endl;
    cin >> key;

    cout << search(array, size, key) << endl;
}
