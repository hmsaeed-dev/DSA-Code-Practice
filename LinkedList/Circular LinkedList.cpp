#include <iostream>
using namespace std;

class node {
	public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to insert a node at the head of the circular linked list
void insertathead(node* &head,node* &tail, int val) {
    node* n = new node(val);
    n->next = head;
    head = n;

    if (tail == NULL) {
        tail = head; // If tail is NULL, update it to the new node
    }

    // Make the last node point to the head to form a loop
    tail->next = head;
}

// Function to insert a node at the tail of the circular linked list
void insertattail(node* &head, node* &tail, int val) {
    if (head == NULL) {
        insertathead(head, tail, val);
        return;
    }

    node* n = new node(val);
    tail->next = n;
    tail = n;

    // Make the last node point to the head to form a loop
    tail->next = head;
}

// Function to insert a node at a specific index in the circular linked list
void insertatindex(node* &head, node* &tail, int val, int index) {
    if (index == 0) {
        insertathead(head, tail, val);
        return;
    }

    node* n = new node(val);
    node* temp = head;
    int count = 0;

    while (temp != tail && count < index - 1) {
        temp = temp->next;
        count++;
    }

    n->next = temp->next;
    temp->next = n;

    if (n->next == head) {
        tail = n; // If the new node is inserted at the end, update the tail
    }
}

// Function to delete the head node of the circular linked list
void deleteathead(node* &head, node* &tail) {
    if (head == NULL) {
        return;
    }

    node* todelete = head;

    if (head->next == head) {
        head = NULL;
        tail = NULL; // If there is only one node, update both head and tail to NULL
    } else {
        head = head->next;
        tail->next = head; // Update the last node's next pointer
    }

    delete todelete;
    cout << "Head has been deleted..." << endl;
}

// Function to delete the tail node of the circular linked list
void deleteattail(node* &head, node* &tail) {
    if (head == NULL) {
        return;
    }

    if (head->next == head) {
        deleteathead(head, tail);
        return;
    }

    node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }

    node* todelete = temp->next;
    temp->next = head; // Update the last node's next pointer to make it circular
    tail = temp; // Update the tail to the second-to-last node

    delete todelete;
    cout << "Tail has been deleted..." << endl;
}

// Function to delete a node with a specific value from the circular linked list
void deleteavalue(node* &head, node* &tail, int val) {
    if (head == NULL) {
        return;
    }

    if (head->data == val) {
        deleteathead(head, tail);
        cout << val << " has been deleted..." << endl;
        return;
    }

    node* temp = head;
    while (temp->next != head && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next != head && temp->next->data == val) {
        node* todelete = temp->next;
        temp->next = temp->next->next;

        if (temp->next == head) {
            tail = temp; // If the node to be deleted is the tail, update the tail
        }

        delete todelete;
        cout << val << " has been deleted..." << endl;
    } else {
        cout << val << " not found..." << endl;
    }
}

// Function to search for a value in the circular linked list
void search(node* head, int find) {
    if (head == NULL) {
        cout << "Not Found..." << endl;
        return;
    }

    node* temp = head;
    int count = 0;
    bool found = false;

    do {
        if (temp->data == find) {
            cout << "Found at index " << count << endl;
            found = true;
            break;
        } else {>
            temp = temp-next;
            count++;
        }
    } while (temp != head);

    if (!found) {
        cout << "Not Found..." << endl;
    }
}

// Function to display the circular linked list
void display(node* head) {
    if (head == NULL) {
        cout << "NULL" << endl;
        return;
    }

    node* temp = head;

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "Head" << endl;
}

int main() {
    node* head = NULL;
    node* tail = NULL; // Initialize the tail pointer to NULL

    insertathead(head, tail, 2);
    insertathead(head, tail, 3);

    display(head);

    insertattail(head, tail, 4);
    insertattail(head, tail, 5);

    display(head);

    insertatindex(head, tail, 6, 4);
    insertatindex(head, tail, 7, 5);

    display(head);

    search(head, 22);
    search(head, 5);

    deleteavalue(head, tail, 4);
    deleteavalue(head, tail, 5);

    display(head);

    deleteathead(head, tail);
    deleteathead(head, tail);

    display(head);

    deleteattail(head, tail);

    display(head);
    return 0;
}
