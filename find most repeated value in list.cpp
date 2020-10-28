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
    	
		void findRepeatedValues(){
			node *iter=head,*iter1;
			int count=0,precount=0,mostRepeatedValue;
			while(iter!=NULL){
				iter1=head;
				while(iter1!=NULL){
					if(iter1->value==iter->value){
						count++;
					}
					iter1=iter1->next;
				}
				if(count>precount){
					mostRepeatedValue=iter->value;
					precount=count;
				}
					count =0;
					iter=iter->next;
		}
			cout<<"The total repeated values in list are :"<<mostRepeatedValue<<endl;
		}
		
};

int main(){
	SinglyLinkedList ll;
	ll.createList(1);
	ll.createList(3);
	ll.createList(1);
	ll.createList(5);
	ll.createList(2);
	ll.createList(5);
	ll.createList(3);
	ll.createList(5);
	ll.createList(5);
	ll.print();
	
	ll.findRepeatedValues();
	
	system("pause");
	return 0;
}

