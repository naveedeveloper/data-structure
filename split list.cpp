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
		
		void split(SinglyLinkedList &l1,SinglyLinkedList &l2,SinglyLinkedList &l3){
			
				int x,z;
				x =counter/2;
				z=counter-x;
				node *iter=head;
				for(int i=0;i<z;i++){
                l2.createList(iter->value);
                iter=iter->next;
				}
				for(int i=0;i<x;i++){
                l3.createList(iter->value);
                iter=iter->next;
				}
				
		}
		
		void print(){
			if(head==NULL){
				cout<<"List is empty!!!"<<endl;
				return;
			}
			
			node* iter=head;
			while(iter!=NULL){
				cout<<iter->value;
				if(iter->next!=NULL){
					cout<<" -> ";
				}
				iter=iter->next;
			}
			cout<<endl;
		}
};
int main(){
	SinglyLinkedList ll,l2,l3;
	ll.createList(1);
	ll.createList(2);
	ll.createList(3);
	ll.createList(4);
	ll.createList(5);
	ll.createList(7);
	ll.createList(8);
	ll.print();
ll.split(ll,l2,l3);
	l2.print();
	l3.print();
	system("pause");
	return 0;
}

