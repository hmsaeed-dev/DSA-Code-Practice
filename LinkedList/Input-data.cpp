//! User Input data to store in the Linked List

#include <iostream>
using namespace std;

class NODE
{
    public:

    int data;
    NODE *link;

    NODE(int value)
    {
        data = value;
        link = nullptr;
    }
};

class LINKEDLIST
{
    public:

    NODE *head;
    NODE *tail;

    LINKEDLIST()
    {
        head = nullptr;
        tail = nullptr;
    }

    ~LINKEDLIST()
    {
        NODE *temp = head;
        while (temp != nullptr)
        {
            NODE *nextNode = temp->link;
            delete temp;
            temp = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }

    void insert(int value)
    {
        NODE *NewNode = new NODE(value);

        if(head == nullptr)
        {
            head = NewNode;
            tail = NewNode;
        }

        else
        {
            tail->link = NewNode;
            tail = NewNode;
        }
    }

    void print()
    {
        NODE *temp = head;
        while(temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->link;
        }
        cout << "Null" << endl;
    }
};

int main()
{
    LINKEDLIST list;
    int UserValue;
    cout << "Enter integers to store (enter -1 to stop):" << endl;

    while(cin >> UserValue)
    {
        if(UserValue == -1){break;}
        list.insert(UserValue);
    }

    cout << endl << "Linked List: " << endl;
    list.print();
}
