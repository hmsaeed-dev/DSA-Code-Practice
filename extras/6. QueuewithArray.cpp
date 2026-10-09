#include <iostream>
using namespace std;

#define n 20

class queue{
	int* arr;
	int front;
	int back;
	
	public:
		queue(){
			arr = new int[n];
			front = -1;
			back = -1;
		}
		
		void enqueue(int x){
			if(back == n-1){
				cout<<"Queue Overflow...";
				return;
			}
			back++;
			arr[back] = x;
			
			if(front == -1){
				front++;
			}
		}
	
		void dequeue(){
			if(front == -1 || front>back){
				cout<<"Queue Underflow";
				return;
			}
			front++;
			
		}
		
		int peek(){
				if(front == -1 || front>back){
				cout<<"Queue Underflow";
				return -1;
			}
			return arr[front];
		}
	
		bool empty(){
				if(front == -1 || front>back){
				cout<<"Queue Underflow";
				return true;
			}
			return false;
		}
		
		void display(){
			if(front == -1 || front > back){
				cout << "Queue is empty." << endl;
				return;
			}
			for(int i = front; i <= back; i++){
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	
};


int main(){
	queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	
	cout<<"No at Front :"<<q.peek()<<endl;
	
	
	q.display();
	
	q.dequeue();
	
	q.display();
	
	q.dequeue();
	q.display();
	
	cout<<"NO at FRont :"<<q.peek()<<endl;
	
	q.dequeue();
	
	cout<<"Status : "<<q.empty()<<endl;
	
}