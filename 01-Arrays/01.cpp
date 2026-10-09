// !Array Insertion

#include <iostream>
using namespace std;

void insert_beg( int array[], int size, int pos)
{

}

void insert_end( int array[], int size, int pos)
{
    size++;

}


void insert_middle( int array[], int size, int pos)
{

}


int main()
{
    int array[];

    int size;
    cout << "Enter the size of array" << endl;
    cin >> size;
    int array[size];

    cout << "Enter numbers" << endl;
    for(int i=0; i<size; i++)
    {
        cin >> array[i] << endl;
    }

    insert_beg();
    insert_end();
    insert_middle();

}
