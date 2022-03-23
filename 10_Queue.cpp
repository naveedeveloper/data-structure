#include <iostream>
using namespace std;
void insert();   //Prototype for insert function
void del();      //Prototype for del funtion
void display();  //prototype for display function

int main() {
   int choice;   //integer variable for making following choice
   cout<<"1) Insert element to the back of the queue"<<endl;
   cout<<"2) Delete element from the front of the queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>choice;
      switch (choice) {
	 case 1: insert();
	 break;
	 case 2: del();
	 break;
	 case 3: display();
	 break;
	 case 4: cout<<"Exit"<<endl;
	 break;
	 default: cout<<"Invalid choice"<<endl;
      }
   } while(choice!=4);
   
   return 0;
}

int queue[100], n = 100, front = - 1, back = - 1;
void insert() {
   int val;
   if (back == n - 1)		//To check if the queue is full
	cout<<"Queue Overflow"<<endl;
   else {
      if (front == - 1)         //To check if the queue is completely empty
	front = 0;
      cout<<"Insert the element in the back of the queue : "<<endl;
      cin>>val;
      back++;
      queue[back] = val;
   }
}
void del() {
   if (front == - 1 || front > back) { //Checking if queue is already empty
      cout<<"Queue Underflow ";
      return ;
   } else {
      cout<<"Element deleted from the front of the queue is : "<< queue[front] <<endl;
      front++;;
   }
}
void display() {
   if (front == - 1)
	cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      for (int i = front; i <= back; i++)  //loop to display elements in the queue
	cout<<queue[i]<<" ";
	 cout<<endl;
   }
}
