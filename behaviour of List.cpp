#include<iostream>
#include<cmath>
using namespace std;

struct node{
	int value;
	node *next;
};

class SinglyLinkedList{
	private:
		node *head;
		int counter;
	public:
		SinglyLinkedList(){
			head=NULL;
			counter=0;
		}
		
		node* createNode(int data){
			node* newNode=new node;
			newNode->value=data;
			return newNode;
		}
		
		node* getTail(){
			node* iter=head;
			while(iter->next!=NULL){
				iter=iter->next;
			}
			return iter;
		}
	
		void createList(int data){
			if(head == NULL){
				head=createNode(data);
				head->next=NULL;
				counter++;
				return;
			}
			node* tail=getTail();
			node* newNode=createNode(data);
			newNode->next=NULL;
			tail->next=newNode;
			counter++;
		}
		
		void print(){
			if(head==NULL){
				cout<<"List is empty!!!"<<endl;
				return;
			}
			
			node* iter=head;
			while(iter!=NULL){
				cout<<iter->value<<" -> ";
				iter=iter->next;
			}
			cout<<endl;
		}
		
		void behaviourOfList(){
			node* iter=head;
			int ascending=0,decending=0;
			int val=iter->value;
			while(iter!=NULL){
				if(val<=iter->value){
					decending++;
				}
				if(val>=iter->value){
					ascending++;	
				}
				iter=iter->next;
			}
			if(ascending==counter){
				cout<<"The list is in ascending order!!!"<<endl;
			}else if(decending==counter){
				cout<<"The list is in descending order!!!"<<endl;
			}else{
				cout<<"The list is unsorted!!!"<<endl;
			}
		}
		
};

int main(){
	SinglyLinkedList ll;
	ll.createList(5);
	ll.createList(4);
	ll.createList(8);
	ll.createList(2);
	ll.createList(1);
	ll.print();
	ll.behaviourOfList();
	
	system("pause");
	return 0;
}

