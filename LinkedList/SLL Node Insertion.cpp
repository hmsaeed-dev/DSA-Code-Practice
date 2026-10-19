//! Insertion of Node at nth place

#include <iostream>
using namespace std;

class NODE
{
    int data;
    NODE *link;

    public:
    NODE(int value)
    {
        data = value;
        link = nullptr;
    }
}

class LINKEDLIST
{
    NODE *head;
    NODE *tail;

    public:
    LINKEDLIST()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert_at(int pos, int val)
    {
        NODE *NewNode = new NODE(val);
        NODE *temp = head;

        for(int i=0; i<(pos-1); i++)
        {
            temp = temp->link;
        }
    }
}

int main()
{

}
