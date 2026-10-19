//! Pushback, Pushfront & Traversal on SLL

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class List
{
    Node *head;
    Node *tail;

    public:
    // Constructor
    List()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Destructor
    ~List()
    {
        // We have to del every node, so traversal is imp
        Node *temp = head;
        while( temp == nullptr )
        {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = tail = nullptr;
    }

    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp -> next;
        }
        cout << "Null";
    }

    void pushfront(int val)
    {
        // Create a new node
        Node *aNode = new Node(val);

        // If list exist
        if(head == nullptr)
        {
            head = aNode;
            tail = aNode;
        }

        else
        {
            // Linking the Node
            aNode -> next = head;

            // Update the Head
            head = aNode;
        }
    }

    void pushback(int val)
    {
        // Create a new node
        Node *aNode = new Node(val);

        // If list exist
        if(head == nullptr)
        {
            head = aNode;
            tail = aNode;
        }

        else
        {
            // Linking the Node
            tail -> next = aNode;

            // Update the Head
            tail = aNode;
        }
    }
};


int main()
{
    List list;
    list.pushfront(3);
    list.pushfront(2);
    list.pushfront(1);

    list.pushback(4);
    list.pushback(5);
    list.pushback(6);

    list.print();
}

