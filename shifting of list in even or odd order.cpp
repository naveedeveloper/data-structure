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
		
		void shifting(){
			node* iter=head;
			int counter=1;
			while(iter!=NULL){
				if(counter%2!=0){
					cout<<iter->value<<" -> ";
				}
				counter++;
				iter=iter->next;
			}
			counter=1;
			iter=head;
			while(iter!=NULL){
				if(counter%2==0){
					cout<<iter->value<<" -> ";
				}
				counter++;
				iter=iter->next;
			}
		}
};

int main(){
	SinglyLinkedList ll;
	ll.createList(1);
	ll.createList(2);
	ll.createList(3);
	ll.createList(4);
	ll.createList(5);
	ll.print();
	ll.shifting();
	
	system("pause");
	return 0;
}

