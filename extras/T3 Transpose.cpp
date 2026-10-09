#include <iostream>
using namespace std;
int main(){

int mylist[3][3] = {{1 ,2 , 3},{4 ,5 , 6},{7 ,8 , 9}}
//					(00,01,02),
//					(10,11,12),
//					(20,21,22)
//
//
for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
		mylist[i][j] = mylist[j][i]	;
	}
}
for(int i =0;i<3;i++){
	for(int j =0;j<3;j++){
		cout<<"My List : "<<mylist[i][j] <<'/t';
	}
	cout<<endl;
}



}
