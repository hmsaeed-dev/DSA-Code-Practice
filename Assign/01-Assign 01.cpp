//! Doubly Linked List Operations
//! Push back, Push front, Pop back, Pop front, Linear Search, Removing node from nth position from end

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyList {
    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyList() {
        head = nullptr;
        tail = nullptr;
    }

    // Destructor to free heap memory
    ~DoublyList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = tail = nullptr;
    }

    // Display the list
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // 1. Push Front (Insert at head)
    void pushfront(int val) {
        Node* aNode = new Node(val);

        // If list is empty
        if (head == nullptr) {
            head = tail = aNode;
        } else {
            aNode->next = head;
            head->prev = aNode;
            head = aNode;
        }
    }

    // 2. Push Back (Insert at tail)
    void pushback(int val) {
        Node* aNode = new Node(val);

        // If list is empty
        if (head == nullptr) {
            head = tail = aNode;
        } else {
            tail->next = aNode;
            aNode->prev = tail;
            tail = aNode;
        }
    }

    // 3. Pop Front (Delete head node)
    void popfront() {
        if (head == nullptr) {
            cout << "List is empty! Cannot pop front." << endl;
            return;
        }

        Node* toDelete = head;

        // If only one node exists
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete toDelete;
        cout << "Popped head successfully." << endl;
    }

    // 4. Pop Back (Delete tail node)
    void popback() {
        if (tail == nullptr) {
            cout << "List is empty! Cannot pop back." << endl;
            return;
        }

        Node* toDelete = tail;

        // If only one node exists
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete toDelete;
        cout << "Popped tail successfully." << endl;
    }

    // 5. Linear Search
    int linearSearch(int find) {
        Node* temp = head;
        int index = 0;

        while (temp != nullptr) {
            if (temp->data == find) {
                cout << "Found " << find << " at index " << index << endl;
                return index;
            }
            temp = temp->next;
            index++;
        }

        cout << find << " not found in the list." << endl;
        return -1;
    }

    // 6. Removing node from nth position from end
    // (1-based: n = 1 means the last node/tail, n = size means the first node/head)
    void removeNthFromEnd(int n) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (n <= 0) {
            cout << "Invalid position: " << n << ". Must be >= 1." << endl;
            return;
        }

        // In a Doubly Linked List with tail, walk backwards (n - 1) times from tail
        Node* temp = tail;
        for (int i = 1; i < n; i++) {
            if (temp->prev == nullptr) {
                cout << "Position " << n << " from end is out of bounds!" << endl;
                return;
            }
            temp = temp->prev;
        }

        cout << "Removing node with value " << temp->data << " (" << n << " from end)..." << endl;

        // Case 1: Single node list
        if (temp == head && temp == tail) {
            head = tail = nullptr;
        }
        // Case 2: Removing the head node
        else if (temp == head) {
            head = head->next;
            head->prev = nullptr;
        }
        // Case 3: Removing the tail node
        else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        // Case 4: Removing a middle node
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
    }
};

int main() {
    DoublyList list;

    cout << "--- 1. Testing Push Front & Push Back ---" << endl;
    list.pushfront(20);
    list.pushfront(10);
    list.pushback(30);
    list.pushback(40);
    list.pushback(50);
    cout << "Current List: ";
    list.print();

    cout << endl << "--- 2. Testing Pop Front & Pop Back ---" << endl;
    list.popfront();
    cout << "After popfront: ";
    list.print();

    list.popback();
    cout << "After popback: ";
    list.print();

    cout << endl << "--- 3. Testing Linear Search ---" << endl;
    list.linearSearch(30);
    list.linearSearch(99);

    cout << endl << "--- 4. Testing Remove Nth From End ---" << endl;
    // Current list is: 20 <-> 30 <-> 40 <-> NULL
    // Let's add elements to demonstrate: 10, 20, 30, 40, 50, 60
    list.pushfront(10);
    list.pushback(50);
    list.pushback(60);
    cout << "List before removal: ";
    list.print(); // 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> 60 <-> NULL

    // Remove 1st from end (tail -> 60)
    list.removeNthFromEnd(1);
    cout << "After removing 1st from end: ";
    list.print();

    // Remove 2nd from end (which is 40 now)
    list.removeNthFromEnd(2);
    cout << "After removing 2nd from end: ";
    list.print();

    // Remove 4th from end (head -> 10)
    list.removeNthFromEnd(4);
    cout << "After removing 4th from end (head): ";
    list.print();

    // Out of bounds test
    list.removeNthFromEnd(10);

    return 0;
}
