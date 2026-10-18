#include <iostream>
using namespace std;
int sum_of_natural_numbers(int n);
int main(){
int n;
cout<<"how many natural no. : ";
cin>>n;
int result = sum_of_natural_numbers(n);
cout<<"The sum of the first "<<n<< "  natural numbers is "<< result;
	
}

sum_of_natural_numbers(int n){
	if (n <= 0){
    	return 0;
	}
    else{
    	return n + sum_of_natural_numbers(n - 1);
	}
        
}
    
