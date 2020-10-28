#include<iostream>
#include<string>
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

		void createList(){
			int data;
			cout<<"Enter value for new node: ";
			cin>>data;
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
				cout<<iter->value;
				if(iter->next!=NULL){
					cout<<" -> ";
				}
				iter=iter->next;
			}
			cout<<endl;
		}
		
		//sorting in increment order
		void sorting(){
			node *iter1,*iter;
			iter=head;
			while(iter->next!=NULL){
				iter1=iter->next;
				while(iter1!=NULL){
					if(iter->value > iter1->value){
						int temp=iter->value;
						iter->value=iter1->value;
						iter1->value=temp;
					}
					iter1=iter1->next;
				}
				iter=iter->next;
			}
		}
};
int main(){
	SinglyLinkedList ll;
	ll.createList();
	ll.createList();
	ll.createList();
	ll.createList();
	ll.createList();
	ll.createList();
	ll.print();
	ll.sorting();
	ll.print();
	
	system("pause");
	return 0;
}

