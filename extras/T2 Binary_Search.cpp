#include <iostream>
using namespace std;
int main(){
	int mylist[] = {2, 3, 32, 44, 45, 54, 68, 545};
	
	int find;
	
	cout<<"Enter Your no. to find : ";
	cin>>find;
	
	int low = 0;
	
	int n = sizeof(mylist) / sizeof(mylist[0]);
	
	int high = (sizeof(mylist) / sizeof(mylist[0]))-1;
	
	int check = 0;
	
	int counter = 0;
	
	while(low<=high){
		int middle = (low + high) / 2;
		if(mylist[middle] == find){
			cout<<"Your No. "<<find<<" is found at "<<middle<<" Index"<<endl;
			check = 1;
			break;
		}
		else if(mylist[middle] > find){
			high = middle - 1;
		}
		else{
			low = middle + 1;
		}
		counter++;
		}
	if(check == 0){
		cout<<"Your Number is not found.....\n";
	}
	cout<<"No of Iterations : "<<counter;		

}
