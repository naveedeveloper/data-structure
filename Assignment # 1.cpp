#include<iostream>
using namespace std;

struct node{
	int value;
	node *next;
	
	node(){
		value=0;
		next=NULL;
	}
};

void LinkedList1(){
	node *head;
	node *temp;
	head=new node;
	cout<<"Enter value please: ";
	cin>>head->value;
	head->next=NULL;
	if(head!=NULL){
		temp=head;
		while(temp!=NULL){
			temp=temp->next;
		}
			node *temp1;
			temp1=new node;
			cout<<"Enter value: ";
			cin>>temp1->value;
			temp1->next=temp->next;
			temp->next=temp1;
	}
}

void LinkedList2(){
	node *head;
	node *temp;
	head=new node;
	cout<<"Enter value please: ";
	cin>>head->value;
	head->next=NULL;

	if(head!=NULL){
		temp=head;
		while(temp!=NULL){
			temp=temp->next;
		}
			node *temp1;
			temp1=new node;
			cout<<"Enter value: ";
			cin>>temp1->value;
			temp1->next=temp->next;
			temp->next=temp1;	}
}

int main(){
	int choice;
	node *list;
	while(true){
	cout<<"1-LinkedList1()"<<endl;
	cout<<"2-LinkedList2()"<<endl;
	cout<<"Enter other number to exit"<<endl;
	cout<<"Enter your choice: ";
	cin>>choice;
	if(choice==1)
	LinkedList1();
	else if(choice==2)
	LinkedList2();
	else break;
	}
	return 0;
}
