#include <iostream>
using namespace std;
int main(){
	int find;
	int mylist[10];
	
	for(int i = 0;i<10;i++){
		cout<<"Enter value no. "<<i+1<<" : ";
		cin>>mylist[i];
	}
	//n = len(mylist)
	int n = sizeof(mylist) / sizeof(mylist[0]);
	
	cout<<"Enter the Number you want to find : ";
	cin>>find;
	
	for(int i = 0;i<n;i++){
		if(mylist[i] == find){
			cout<<"Your No. "<<find<<" is found at "<<i<<" Index";
			break;
		}
	}
}
