 #include<iostream>
#include <iomanip>
#include<fstream>
using namespace std;

//Some Global Variables:

int reserve = 9999;
int size = 100 ;  //This Is the Total Number Of Seats Available For Reservations
int seat[100];
bool taken = false;
int cancel=0;

//This Function Makes All The Seats Available For The Passangers
void seatfill()
{
	for(int i=0;i<size;i++)
	{
		seat[i]=0;
	}
}

//This Function Shows The Number Of Seats Empty

void showempty_seats()
{
	for(int i=0;i<size;i++)
	{
		if(seat[i]==0)
		{
			cout<<"| "<<i+1<<" |";
		}
		if((i+1)%10==0)
		{
			cout<<endl;
		}
	}
}

//This Function Checks Seats

void checkSeat(int s)
{
	if(seat[s]==0)
	{
		taken=false;
		
	}
	else
	{
		cout<<"Please Enter The Seat Number From The Following Available Seats!"<<endl;
		cout<<"\n--------------------------------\n";
		showempty_seats();
		cout<<"\n--------------------------------\n";
		
	}
}

class airlines
{
	private:
		struct node{
			string fname , lname , id , phone_num , menu;
			int reserve_num , seat_num;
			node* next;
		};
		node* start;
		node *temp , *temp2;
	
	public:
		airlines();		// Default Constructor For The Airline Class
		void menu();	// Function Which Prints Menu Function
		void make_reservation();
		void cancel_reservation();
		void show_passengers();
		void search_passenger();
		void change_reservation();
		void print_report();
		
}ihksky;




//The Function Which Shows The Menu

void menu()
{
	int choice;
	do{
	cout <<"\t\t ------------------------------ \n";
	cout <<"\t\t Make Reservation    ...... '1' \n";
	cout <<"\t\t ------------------------------ \n";
	cout <<"\t\t Cancel Reservation  ...... '2' \n ";
	cout <<"\t\t ------------------------------ \n";
	cout <<"\t\t Search Passenger    ...... '3' \n";
	cout <<"\t\t ------------------------------ \n";
	cout <<"\t\t Change Reservation  ...... '4' \n";
	cout <<"\t\t ------------------------------ \n";
	cout <<"\t\t Print a list        ...... '5' \n";
	cout <<"\t\t ------------------------------ \n";
	cout <<"\t\t Print status Report ...... '6' \n ";
	cout <<"\t\t ------------------------------ \n";
	cout <<"\t\t Quit                ...... '7' \n "; 
	cout <<"\t\t ------------------------------ \n";
	cout <<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	cout <<"\n Option :: ";
	cin >> choice;
	switch (choice)
	{
		case 1:
			system("CLS");
			ihksky.make_reservation();
			break;
		case 2:
			system("CLS");
			ihksky.cancel_reservation();
			break;
		case 3:
			system("CLS");
			ihksky.search_passenger();
			break;
		case 4:
			system("CLS");
			ihksky.change_reservation();
			break;
		case 5:
			system("CLS");
			ihksky.show_passengers();
			break;
		case 6:
			system("CLS");
			ihksky.print_report();
			break;
		case 7:
			system("CLS");
			cout <<"\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
			cout<<"Prsesented By:\n";
			cout<<"Hamza Malik (22-CS-86)"<<endl;

			cout <<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
			break;
		default:
			cout<<"Enter A Valid Option!!"<<endl;
			break;
	}
	if(choice!=7)
	{
	
	cout <<"\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	cout<<"You Have Completed An Operation Successfully"<<endl;
	cout<<"Press Any Key To Goto Main Menu!"<<endl;
	cout <<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	
	cin.get();
	if(cin.get()=='\n')
		system("CLS");
}
		
	}while(choice!=7);
}


//Default Constructor which sets the pointer to null.
airlines::airlines()	
{
	start = NULL;
}

//The Function Which Makes The Reservation For A Flight

void airlines::make_reservation()
{
	int food_choice , x;
	
	
	
	
	temp = new node;
	cout<<"Enter The First Name Of The Person:"<<endl;
	cin>>temp->fname;
	cout<<"--------------------------------"<<endl;
	
	cout<<"Enter The Last Name Of The Person:"<<endl;
	cin>>temp->lname;
	cout<<"--------------------------------"<<endl;
	
	cout<<"Enter The ID Of The Person:"<<endl;
	cin>>temp->id;
	cout<<"--------------------------------"<<endl;
	
	cout<<"Enter The Phone Number Of The Person:"<<endl;
	cin>>temp->phone_num;
	cout<<"--------------------------------"<<endl;
	
	
	
	do
	{	
		
		cout<<"Please Enter The Seat Number From The Following Available Seats!"<<endl;
		cout<<"\n--------------------------------\n";
		showempty_seats();
		cout<<"\n--------------------------------\n";
		cin>>x;
		while(x>size)
		{
			cout<<"Please Enter A Valid Seat Number!"<<endl;
			cout<<"The Seat Numbers Are From 1-100"<<endl;
		cin>>x;
		}
		cout<<"\n\n";
		
		if(seat[x-1]>-1)
		{
			taken = false;
		}
		else
		{
			checkSeat(x);
		}
		seat[x-1]=-1;
		temp->seat_num=x;
	}while(taken==true);
	
	
	
	cout<<"\n--------------------------------\n";
	cout<<"Enter The Food Choice!"<<endl;
	cout<<"Press 1 For Desi Food."<<endl;
	cout<<"Press 2 For Mexican Food."<<endl;
	cout<<"Press 3 For Chinese Food."<<endl;
	cout<<"Press 4 For Italian Food."<<endl;
	cout<<"Press 5 For No Food."<<endl;
	
	while(food_choice>5||food_choice<1)
	{
		cout<<"You Have Entered Wrong Choice Please Try Again!"<<endl;
		cin>>food_choice;
	}
	if(food_choice==1)
	{
		temp->menu="Desi";
	}else if(food_choice==2)
	{
		temp->menu="Mexican";
	}
	else if(food_choice==3)
	{
		temp->menu="Chinese";
	}
	else if(food_choice==4)
	{
		temp->menu="Italian";
	}
	else
	{
		temp->menu = "No Food";
	}
	
	reserve++;
	temp->reserve_num=reserve;
	cout <<"\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	cout << "YOUR RESERVATION NUMBER IS :: " << reserve << "\n";
	cout <<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	 temp->next = NULL;
	 
	 if(start == NULL)
	 {
	 	start = temp;
	 }
	 else
	 {
	 	temp2 = start;
	 	while(temp2->next!=NULL)
	 	{
	 		temp2 = temp2->next;
		 }
		 temp2->next = temp;
		 
	 }
	 
	 
	 ofstream obj("Airlines List.txt",ios::app);
	obj<<"First Name: "<<temp->fname<<endl;
	obj<<"Last Name: "<<temp->lname<<endl;
	obj<<"ID: "<<temp->id<<endl;
	obj<<"Phone Number: "<<temp->fname<<endl;
	obj<<"Seat Number: "<<temp->seat_num<<endl;
	obj<<"Food Menu: "<<temp->menu<<endl;
	obj<<"Reservation Number: "<<temp->reserve_num<<endl;
}

//This Function Cancels Or Deletes The Reservation Of A Flight 

void airlines :: cancel_reservation()
{
//	int res_num;
//	
//	cout<<"Enter Your Reservation Number"<<endl;
//	cin>>res_num;
//	
//	node* cur = start;
//	if(cur!=NULL)
//	{
//		// IF The Entered Number is At The Start Of The Node Then Deletes The Node
//		if(cur->reserve_num==res_num)
//		{
//			node* tempp = cur;
//			cur = cur->next;
//			seat[tempp->seat_num-1]=0;
//			delete tempp;
//			cancel++;return;
//		}
//		
//		//This Deletes The Node Placed In Middle Or End Of The Linked List
//		else
//		{
//			while(cur->next->reserve_num!= res_num)
//			{
//				cur = cur->next;
//			}
//			node * tempp = cur;
//			cur= cur->next->next;
//			seat[tempp->seat_num-1]=0; 
//			delete tempp;
//			cancel++;
//		}
//		
//	}
//	else
//	{
//		cout<<"No Flights Reserved By Such Reservation Number"<<endl;
//	}


int num;
	cout << "Please Enter your reservation Number here: ";
	cin >> num;

		node *cur = start;
		if(cur!=NULL)
		{ // error checking for empty node deletion which cause segm fault error.

		if ( start->reserve_num == num )	//first node.
		{
			node *del = start;
			start = start->next;
			seat[del->seat_num-1] = 0;
			delete del;
			cancel++;
			return;
		}
		else
		{
			node *pre, *cur; 	//To delete a middle or last node.
			pre = start;
			cur = start->next;
			while(cur != NULL)
			{
				if ( cur->reserve_num == num )
						break;
				pre = cur;
				cur = cur->next;
			}
			seat[cur->seat_num-1] = 0;	
			if (cur != NULL )
			pre->next = cur->next;
			cancel++;
				
		}

	
	//reserve--;
	//temp->reserve_num=reserve;

		}// error checking if statement ends here
		else
		{
		cout<<"!!! *** Nothing to delete or invalid entry *** !!! \n"<<endl;
		}	
}

//This Function Shows All the Passenger List

void airlines ::show_passengers()
{
	temp = start;
	if(temp==NULL)
	{
		cout<<"No Passengers Found!"<<endl;
	}
	else
	{
		int cnt = 1;
		cout << "\tNumber\t First Name\t Last Name\t I.D.\t";
		cout << "Phone Number\t Seat Number\t Reservation No.\t Menu\n"; 
		
		// Display details for All The Passengers in List
		
		while(temp != NULL)	
		{
			cout << "\t" << cnt <<setw(15);
			cout << temp->fname <<setw(15);
			cout << temp->lname << setw(12);
			cout << temp->id << setw(12);
			cout << temp->phone_num <<setw(15);
			cout << temp->seat_num <<setw(15);
			cout << temp->reserve_num <<setw(16);
			cout <<"\t"<< temp->menu << "\n";
			// Move to next node
			temp=temp->next;
			cnt++;
		}
		cout << "\n\n";
	}
}

//Function To Search Passenger in  The Reservations
 void airlines :: search_passenger()
 {
 	string tempName;
 	int found = 0;
 	
 	cout<<"Enter The First Name Of The Passanger You Want To Search"<<endl;
 	cin>>tempName;
 	
 	node *cur = start;
 	
 	while(cur!=NULL)
 	{
 		if(cur->fname == tempName)
 		{
 			cout << "First Name : " << cur->fname << endl;
				cout << "Last Name : " << cur->lname << endl;
				cout << "ID " << cur->id << endl;
				cout << "Phone number: " << cur->phone_num << endl;
				cout << "seat Number: " << cur->seat_num << endl;
				cout << "Reservation No. " << cur->reserve_num<< endl;
				found = 1;
		 }
		 cur= cur->next;
	 }
	 
	 if(found==0)
	 {
	 	cout<<"No User Found With The Given Name In Reservations!!"<<endl;
	 }
 }
 
 void airlines :: change_reservation()
 {
 	int option , next_seat;	
	cout << " Please enter your seat number: ";
	cin >> option;
	node *cur;
	cur = start;
	int found = 0;
	
	while(cur != NULL)
	{
		if ( cur->seat_num == option )
			{
				found = 1;
				break;
			}
		cur = cur->next;
	}		
	if(found==1)
	{
		
	cout << "Please choose another seat number from below.";
		int j = 1;
		while ( j < size+1 )
		{
			if ( seat[j-1] == -1)
			j++;
			else
			{	
			cout <<"| " << j << "|";
			if ( j%10 == 0 )
			cout << endl;
			j++;	
			}
		}	
	cin >> next_seat;
	seat[cur->seat_num-1]=0;
	cur->seat_num = next_seat;
	seat[next_seat-1] = -1;
	
	cout<<"Your Seat Has Been Changed To Seat Number: "<<next_seat<<"."<<endl;
}
else
{
	cout<<"No Reservations By Such Seat Number!!"<<endl;
}
					
 }


void airlines:: print_report()	 //This function prints the status report of the flight.
{	int count = 0;
	for (int i =0; i < size; i++ )
	{
		if (seat[i] == -1)
			count++;
	}
	cout<<"The number of reserved seats are: " << count <<endl;
	cout<<"The number of cancellations are: " << cancel <<endl;
}


int main()
{
	// Cleans The Screen
	system("CLS");
	
	cout<<"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout << "\t     WELCOME TO maya.wings AIRLINE RESERVATION SYSTEM \n";
	cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout<<" ..................... MENU OPTIONS .............................\n"<<endl;
	
	menu();
	seatfill();
}
