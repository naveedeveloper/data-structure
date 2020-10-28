#include<iostream>
#include<string>
#include<cmath>
using namespace std;

struct node{
	int value;
	node* pre;
	node* next;
};

class DoublyLinkedList{
	private:
		node* head;
	public:
		DoublyLinkedList(){
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
		
		node* searching(int key){
			if(head==NULL){
				cout<<"List is empty!!!"<<endl;
				return NULL;
			}
			
			node *iter=head;
			bool found=false;
			while(iter!=NULL){
				if(iter->value==key){
					found=true;
					break;
				}
				iter=iter->next;
			}
			if(found==false)
				cout<<"key not found!!!"<<endl;
			else
				return iter;
		}
		
		void createList(){
			int data;
			cout<<"Enter data for new value: ";
			cin>>data;
			if(head==NULL){
				head=createNode(data);
				head->pre=NULL;
				head->next=NULL;
				return;
			}
			node* tail=getTail();
			node* newNode=createNode(data);
			newNode->next=NULL;
			tail->next=newNode;
			newNode->pre=tail;
			
		}
		
		void insertionOfNewNodeByValue(){
			int key,value;
			cout<<"Enter key to search : ";
			cin>>key;
			cout<<"Enter value of new node : ";
			cin>>value;
			node* search=searching(key);
			node* newNode=createNode(value);
			newNode->next=search->next;
			search->next=newNode;
			newNode->pre=search;
		}
		
		void deletion(){
			if(head==NULL){
				cout<<"List is empty!!!"<<endl;
				return;
			}
			int key;
			cout<<"Enter key to search: ";
			cin>>key;
			
			node* search=searching(key);
			node* temp=search;
			if(search == head){
				head=head->next;
				delete temp;
				head->pre=NULL;
				return;
			}
			
			search->pre->next=search->next;
			delete temp;
		}
		
		void print(){
			if(head==NULL){
				cout<<"List is empty!!!"<<endl;
				return;
			}
			
			node* iter=head;
			while(iter!=NULL){
				cout<<iter->value<<" ";
				iter=iter->next;
			}
			cout<<endl;
		}
		
};
int main(){
	DoublyLinkedList ll;
	ll.createList();
	ll.createList();
	ll.createList();
	ll.createList();
	ll.print();
	
	ll.insertionOfNewNodeByValue();
	ll.insertionOfNewNodeByValue();
	ll.insertionOfNewNodeByValue();
	ll.print();

	ll.deletion();
	ll.print();
		
	system("pause");
	return 0;
}

