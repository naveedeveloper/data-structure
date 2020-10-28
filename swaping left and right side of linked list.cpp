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
	public:
		SinglyLinkedList(){
			head=NULL;
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
				return;
			}
			node* tail=getTail();
			node* newNode=createNode(data);
			newNode->next=NULL;
			tail->next=newNode;
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
		
		int midPoint(){
		    int mid,counter=0;
		    node* iter=head;
		    while(iter!=NULL){
		        counter++;
		        iter=iter->next;
		    }
		    mid=ceil(counter/2);
		    return mid;
		}
		
		void swaping(){
			node* iter=head;
			int counter=0;
			while(iter!=NULL){
				counter++;
				if(counter>midPoint()){
					cout<<iter->value<<" -> ";
				}
				iter=iter->next;
			}
			iter=head;
			counter=0;
			while(iter!=NULL){
				counter++;
				if(counter==midPoint()){
					cout<<iter->value<<" -> ";
					break;
				}
				iter=iter->next;
			}
			iter=head;
			counter=0;
			while(iter!=NULL){
				counter++;
				if(counter<midPoint()){
					cout<<iter->value<<" -> ";
				}
				iter=iter->next;
			}
			cout<<endl;
		}
};

int main(){
	SinglyLinkedList ll;
	ll.createList(1);
	ll.createList(2);
	ll.createList(3);
	ll.createList(4);
	ll.createList(5);
	ll.createList(6);
	ll.createList(7);
	ll.createList(8);
	ll.createList(9);
	ll.createList(12);
	ll.createList(55);
	ll.createList(33);
	ll.print();
	cout<<"mid point: "<<ll.midPoint()<<endl;
    ll.swaping();
	
	system("pause");
	return 0;
}

