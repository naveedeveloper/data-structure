#include<iostream>
#include<string>
#include<cmath>
using namespace std;

struct node{
	int value;
	node* next;
};

class Stack{
	private:
		node* top;
		int limit,counter;
	public:
		Stack(){
			top=NULL;
			limit=4;
			counter=0;
		}
		
		node* createNode(int data){
			node* newNode=new node;
			newNode->value=data;
			return newNode;
		}
		
		bool isEmpty(){
			if(top==NULL)
				return true;
			else
				return false;
		}
		
		void push(){
			int value;
			if(counter>=limit){
				cout<<"Stack overflow!!!"<<endl;
				return;
			}
			
			cout<<"Enter value for new node: ";
			cin>>value;
			
			node* newNode=createNode(value);
			newNode->next=top;
			top=newNode;
			counter++;
		}
		
		void pop(){
			int x=0;
			if(isEmpty()){
				cout<<"Stack underflow!!!"<<endl;
			
			}else{
				node* temp=top;
				top=top->next;
				counter--; 
				delete temp;
			}
		}
		
		void print(){
			if(isEmpty()){
				cout<<"Stack underflow!!!"<<endl;
				return;
			}
			cout<<"<<<<<<<Stack>>>>>>"<<endl;
			node *iter=top;
			while(iter!=NULL){
				cout<<iter->value<<endl;
				iter=iter->next;
			}
		}
		
};
int main(){
	Stack obj;
	
	cout<<obj.isEmpty()<<endl;
	obj.push();
	obj.push();
	obj.push();
	obj.push();
	obj.print();
	
	obj.pop();
	obj.print();
	obj.pop();
	obj.print();
	obj.pop();
	obj.print();
	obj.pop();
	obj.print();
	
	system("pause");
	return 0;
}

