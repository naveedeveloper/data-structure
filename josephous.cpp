#include<iostream>
#include<string>
#include<cmath>
using namespace std;

struct node{
	int value;
	node *next;
};

class SinglyRingList{
	private:
		node *head;
	public:
		SinglyRingList();
		
		node* createNode(int data);
	
		node* getTail();

		void createList(int data);
		
		void print();
		
		int josephous();
};
SinglyRingList::SinglyRingList(){
	head=NULL;
}

node* SinglyRingList::createNode(int data){
	node* newNode=new node;
	newNode->value=data;
	return newNode;
}

node* SinglyRingList::getTail(){
	node* iter=head;
	while(iter->next!=head){
		iter=iter->next;
	}
		return iter;
}

void SinglyRingList::createList(int data){
	if(head == NULL){
		head=createNode(data);
		head->next=head;
		return;
	}
		node* tail=getTail();
		node* newNode=createNode(data);
		newNode->next=head;
		tail->next=newNode;
}

void SinglyRingList::print(){
	if(head==NULL){
	cout<<"List is empty!!!"<<endl;
	return;
	}
			
	node* iter=head;
	do{
	cout<<iter->value<<" ";
	iter=iter->next;
	}while(iter!=head);
	cout<<endl;
}

int SinglyRingList::josephous(){
	int val;
	node* iter=head;
	node* del=head->next;
	while(head->next != head){
		for(int i=0;i<4;i++){
			iter=iter->next;
			del=del->next;
		}
		iter->next=del->next;
		if(del == head){
			head=head->next;
		}
		val=del->value;
		delete del;
		cout<<" ( "<<val<<"out ) "<<endl;
		iter=iter->next;
		del=iter->next;
	}
	return head->value;
}
int main(){
	SinglyRingList ll;
	ll.createList(1);
	ll.createList(2);
	ll.createList(3);
	ll.createList(4);
	ll.createList(5);
	ll.createList(6);
	ll.createList(7);
	ll.createList(8);
	ll.createList(9);
	ll.createList(10);
	ll.print();
	cout<<ll.josephous()<<endl;
	system("pause");
	return 0;
}

