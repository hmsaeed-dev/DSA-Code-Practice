//! Insertion & Deletion

#include <iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;

		node(int val){
			data = val;
			next = NULL;
		}
};

void insertathead(node* &head,int val){
	node* n = new node(val);
	n->next = head;
	head = n;
}

void insertattail(node* &head,int val){
	node* n = new node(val);

	node* temp = head;

	if(head==NULL){
		insertathead(head,val);
		return;
	}

	while(temp->next != NULL){
		temp = temp->next;
	}

	temp->next = n;

}


void insertatindex(node* &head,int val,int index){
	node* n = new node(val);

	node* temp = head;
	int count = 0;

	while(temp != NULL && count<index-1){
		temp = temp->next;
		count++;
	}

	n->next = temp->next;
	temp->next = n;

}

void deleteathead(node* &head){
	node* todelete = head;

	head = head->next;

	delete todelete;
	cout<<"Head has been deleted..."<<endl;

}

void deleteattail(node* &head){
	node* temp = head;

	while(temp->next->next != NULL){
		temp = temp->next;
	}

	node* todelete = temp->next;
	temp->next = NULL;


	delete todelete;
	cout<<"Tail has been deleted..."<<endl;

}


void deleteavalue(node* &head,int val){
	if(head == NULL){
		return;
	}

	// if linked list has only one element
	if(head->next == NULL){
		deleteathead(head);
	}



	node* temp = head;

	while(temp->next->data != val){
		temp = temp->next;
	}

	node* todelete = temp->next;

	temp->next = temp->next->next;

	delete todelete;
	cout<<val<<" has been deleted..."<<endl;

}


void search(node* head,int find){
	node* temp = head;
	int count=0;
	bool found = false;


	while(temp != NULL){
		if(temp->data == find){
			cout<<"Found at index "<<count<<endl;
			found = true;
			break;
		}
		else{
			temp = temp->next;
			count++;
		}
	}

	if(!found){
		cout<<"Not Found..."<<endl;
	}
}


void display(node* head){
	node* temp = head;

	while(temp != NULL){
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}



int main(){
	node* head = NULL;

	insertathead(head,2);
	insertathead(head,3);

	display(head);

	insertattail(head,4);
	insertattail(head,5);

	display(head);

	insertatindex(head,6,4);
	insertatindex(head,7,5);

	display(head);

	search(head,22);
	search(head,5);

	deleteavalue(head,4);
	deleteavalue(head,5);

	display(head);

	deleteathead(head);
	deleteathead(head);

	display(head);

	deleteattail(head);


	display(head);

}
