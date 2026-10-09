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

class Stack {
    node* top;

	public:
    	Stack() {
        	top = NULL;
    	}

    	void push(int x) {
        	node* n = new node(x);
        	n->next = top;
        	top = n;
    	}

    void pop() {
        if (top == NULL) {
            cout << "No element to pop" << endl;
            return;
        }

        node* temp = top;
        top = top->next;
        delete temp;
    }

    int Top() {
        if (top == NULL) {
            cout << "No element in stack" << endl;
            return -1;
        }
        return top->data;
    }

    bool empty() {
        return top == NULL;
    }
};

int main() {

    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.empty() << endl;

    return 0;
}
