#include <iostream>
using namespace std;

class node{
	public:
		int data;
		node* left;
		node* right;

		node(int val){
			data = val;
			left = NULL;
			right = NULL;
		}
};

node* insertBST(node* root,int val){
	
	if(root == NULL){
		return new node(val);
	}
	
	if(val < root->data){
		root->left = insertBST(root->left,val);
	}
	else{
		root->right = insertBST(root->right,val);
	}
	
	return root;
		
}

void inorder(node* root){
	if(root == NULL){
		return;
	}
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}


node* Search(node* root,int key){
	if(root == NULL){
		return NULL;
	}
	
		
	if(root->data == key){
		return root;
	}
	
	if(root->data > key){
		return Search(root->left,key);
	}
	
	return Search(root->right,key);
}


int main(){
	node* root = NULL;
//	int rootnode;
	
//	cout<<"Enter Value for Root node :"
//	cin>>rootnode;
	root = insertBST(root,5);
	insertBST(root,1);
	insertBST(root,3);
	insertBST(root,4);
	insertBST(root,2);
	
	
	inorder(root);
	cout<<endl;
	
	if(Search(root,9) == NULL){
		cout<<"Not exist";
	}
	else{
		cout<<"existssss";
	}
	
	
	return 0;
}






