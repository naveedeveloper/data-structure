#include<iostream>
using namespace std;
class Stack{
	int arr[10];
	int *ptr,*top;
	int limit;
public:
	Stack(){
		ptr=NULL;
		ptr=arr;
		limit=0;
	}
	
	bool isEmpty(){
		if(limit==0)
			return true;
		else
			return false;
	}
	
	void push(){
	  if(limit<10){
	  	cout<<"Enter value : ";
	  	cin>>*ptr;
	  	ptr++;
	  	top=ptr;
	  	limit++;
	  }else{
	  	cout<<"stack over flow"<<endl;
	  }
	}
	
	void print(){
		if(isEmpty()){
			cout<<"Stack underflow!!!"<<endl;
			return;
		}
		ptr=top;
		for(int i=0;i<=limit;i++){
			cout<<*ptr<<endl;
			ptr--;
		}
		cout<<endl;
    }
    
  	void pop(){
  		if(isEmpty()){
  			cout<<"Stack underflow!!!"<<endl;
			return;
		}
		top--;
		limit--;
	}
};
int main()
{
	Stack obj;
	cout<<"Stack is empty: "<<obj.isEmpty()<<endl;
	obj.push();
	obj.push();
	obj.push();
	obj.push();
	obj.push();
	obj.print();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.print();
	cout<<"Stack is empty: "<<obj.isEmpty()<<endl;	
	
	return 0;
}
