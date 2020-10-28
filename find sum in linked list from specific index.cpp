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
		
		void findSum(int index){
			node* iter=head;
			int sum=0,counter=0;
			
			while(iter!=NULL){
				if(counter>=index){
					sum+=iter->value;
				}
				counter++;
				iter=iter->next;
			}
			cout<<"The sum is : "<<sum<<endl;
		}
		
};

int main(){
	SinglyLinkedList ll;
	ll.createList(3);
	ll.createList(7);
	ll.createList(4);
	ll.createList(1);
	ll.createList(8);
	ll.createList(9);
	ll.print();
	ll.findSum(4);
	
	system("pause");
	return 0;
}

