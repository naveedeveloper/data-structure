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
		SinglyRingList(){
			head=NULL;
		}
		
		node* createNode(int data){
			node* newNode=new node;
			newNode->value=data;
			return newNode;
		}
		
		node* getStart(){
			return head;
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
			node* iter=head;
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
				cout<<"Key is not found in list!!!"<<endl;
			else
				return iter;
		}
		
		node* getPrev(node* randomNode){
	        node* iter = head;
	        if (randomNode==NULL)
	                return NULL;
	        if (randomNode==head)return head;
	        while(iter->next!=randomNode){
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
				head->next=head;
				return;
			}
			node* tail=getTail();
			node* newNode=createNode(data);
			newNode->next=head;
			tail->next=newNode;
		}
		
		void insertionOfNewNodeByValue(){
			int value,key;
			cout<<"Enter key to search: ";
			cin>>key;
			cout<<"Enter value for new node: ";
			cin>>value;
			
			node* tail=getTail();
			node* search=searching(key);
		
			node* newNode=createNode(value);
			newNode->next=search->next;
			search->next=newNode;
			
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
			node* pre=getPrev(search);
			if(search==head){
				node* temp=search;
				if(search->next!=head)
					head=head->next;
				else
					head=NULL;
				delete temp;
				return;
			}
			node* temp=search;
			pre->next=pre->next->next;
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
	SinglyRingList ll;
	ll.createList();
	ll.createList();
	ll.createList();
	ll.print();

	ll.insertionOfNewNodeByValue();
	ll.print();
	
	ll.deletion();
	ll.print();
	
	system("pause");
	return 0;
}

