#include<iostream>
using namespace std;
void push(int);  //Prototype for function push
void pop();      //Prototype for function pop
void display();  //prototupe for function display

int main() {	
   int ch, val;           //ch is for type of choice and val is used to enter and remove a data value.
   cout<<"1) Push value in the stack"<<endl;
   cout<<"2) Pop value from the stack"<<endl;
   cout<<"3) Display the stack"<<endl;
   cout<<"4) Exit the program"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
	 case 1: { //To push value into the stack
	    cout<<"Enter value to be pushed:"<<endl;
	    cin>>val;
	    push(val);
	    break;
	 }
	 case 2: {
	    pop();// calling pop function to pop the value at the top
	    break;
	 }
	 case 3: {
	    display();  //To display all elements in the stack
	    break;
	 }
	 case 4: {
	    cout<<"Press any key to Exit"<<endl;
	    break;
	 }
	 default: {
	    cout<<"Invalid Choice"<<endl;
	 }
      }
   }while(ch!=4);
   
   return 0;
}
//stack is an array where as n is the length of the array
//Here we are using top=-1 to start with and to restrict
//elements to the length of the array
int stack[100], n=100, top=-1;

void push(int val) {
   if(top>=n-1) //We cannot have more elements than the length of the stack(array)
   cout<<"Stack Overflow\n"<<endl;
   else {
      top++;
      stack[top]=val;
   }
}
void pop() {
   if(top<=-1)//Check if the stack is empty
   cout<<"Stack Underflow\n"<<endl;
   else {
      cout<<"The popped element is "<< stack[top] <<endl;
      top--;
   }
}
void display() {
   if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
	cout<<stack[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty\n";
}
