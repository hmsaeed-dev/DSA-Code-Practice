#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev; // Added a pointer to the previous node

    node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertathead(node* &head, int val) {
    node* n = new node(val);
    n->next = head;
    n->prev = NULL; // The new node is the head, so its previous is NULL

    if (head != NULL) {
        head->prev = n; // Update the previous of the current head
    }

    head = n;
}

void insertattail(node* &head, int val) {
    node* n = new node(val);

    if (head == NULL) {
        head = n;
        return;
    }

    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp; // Update the previous pointer of the new node
}

void insertatindex(node* &head, int val, int index) {
    if (index == 0) {
        insertathead(head, val);
        return;
    }

    node* n = new node(val);
    node* temp = head;
    int count = 0;

    while (temp != NULL && count < index - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        // Index is out of bounds, you may choose to handle it differently
        cout << "Index out of bounds" << endl;
        delete n;
        return;
    }

    n->next = temp->next;
    n->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = n; // Update the previous pointer of the next node
    }
    temp->next = n;
}

void deleteathead(node* &head) {
    if (head == NULL) {
        return;
    }

    node* todelete = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL; // Update the previous of the new head
    }

    delete todelete;
    cout << "Head has been deleted..." << endl;
}

void deleteattail(node* &head) {
    if (head == NULL) {
        return;
    }

    if (head->next == NULL) {
        deleteathead(head);
        return;
    }

    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;
    cout << "Tail has been deleted..." << endl;
}

void deleteavalue(node* &head, int val) {
    if (head == NULL) {
        return;
    }

    if (head->data == val) {
        deleteathead(head);
        cout << val << " has been deleted..." << endl;
        return;
    }

    node* temp = head;
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << val << " not found..." << endl;
        return;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << val << " has been deleted..." << endl;
}

void search(node* head, int find) {
    node* temp = head;
    int count = 0;
    bool found = false;

    while (temp != NULL) {
        if (temp->data == find) {
            cout << "Found at index " << count << endl;
            found = true;
            break;
        } else {
            temp = temp->next;
            count++;
        }
    }

    if (!found) {
        cout << "Not Found..." << endl;
    }
}

void display(node* head) {
    node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    node* head = NULL;

    insertathead(head, 2);
    insertathead(head, 3);

    display(head);

    insertattail(head, 4);
    insertattail(head, 5);

    display(head);

    insertatindex(head, 6, 2);
    insertatindex(head, 7, 0);

    display(head);

    search(head, 22);
    search(head, 5);

    deleteavalue(head, 4);
    deleteavalue(head, 3);

    display(head);

    deleteathead(head);
    deleteathead(head);

    display(head);

    deleteattail(head);

    display(head);

    return 0;
}
