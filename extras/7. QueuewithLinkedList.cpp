#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue{
    node* front;
    node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int x) {
        node* n = new node(x);

        if (rear == NULL) {
            front = n;
            rear = n;
            return;
        }

        rear->next = n;
        rear = n;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow" << endl;
            return;
        }

        node* temp = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    int peek() {
        if (front == NULL) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return front->data;
    }

    bool empty() {
        return front == NULL;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }

        node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Number at Front: " << q.peek() << endl;

    q.display();

    q.dequeue();

    q.display();

    q.dequeue();
    q.display();

    cout << "Number at Front: " << q.peek() << endl;

    q.dequeue();

    cout << "Status: " << q.empty() << endl;

    return 0;
}
