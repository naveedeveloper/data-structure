#include<iostream>
#include<string>
#include<cmath>
using namespace std;

struct node{
	int value;
	node* pre;
	node* next;
};

class DoublyRingList{
	private:
		node* head;
	public:
		DoublyRingList(){
			head=NULL;
		}
		
		node* createNode(int data){
			node* newNode=new node;
			newNode->value=data;
			return newNode;
		}
		
		node* getTail(){
			node* iter=head;
			while(iter->next!=head){
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
			if(iter->value==key){
				return head;
			}
			
			while(iter->next!=head){
				if(iter->value==key){
					found=true;
					break;
				}
				iter=iter->next;
			}
			if(iter->next==head){
				return iter;
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
				head->pre=head;
				head->next=head;
				return;
			}
			node* tail=getTail();
			node* newNode=createNode(data);
			newNode->next=head;
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
				if(head->next!=head){
					head=head->next;
					head->pre=head;
				}
				else
					head=NULL;
				delete temp;
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
			do{
				cout<<iter->value<<" ";
				iter=iter->next;
			}while(iter!=head);
			cout<<endl;
		}
		
};
int main(){
	DoublyRingList ll;
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

