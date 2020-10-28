#include<iostream>
using namespace std;

struct node{
	int value;
	node *next;
};

class SinglyLinkedList{
	private:
		node *head,*iter;
		int check;
	public:
		SinglyLinkedList(){
			head=NULL;
			check=0;
		}
		
		node* createNode(int data){
			node* newNode=new node;
			newNode->value=data;
			return newNode;
		}

		node* getTail(){
			if(check==0){
				iter=head;
				check++;
			}
			if(iter->next==NULL){
				check=0;
				return iter;
			}
				iter=iter->next;
				getTail();
		}
		
		node* searching(int key){
			if(head==NULL){
				cout<<"List is empty!!!"<<endl;
				return NULL;
			}
			
			if(check==0){
				iter=head;
				check++;
			}
			
			
			if(iter->value==key){
				check=0;
				return iter;
			}
				iter=iter->next;
			if(iter==NULL){
				cout<<"Key not found!!!!"<<endl;
				check=0;
				return NULL;
			}
			searching(key);
		}
		
		node* getPrev(node* randomNode){
	        if(check==0){
	        	check++;
				iter = head;
			}
			
	        if (randomNode==NULL)return NULL;
	        
			if (randomNode==head)return head;
	        if(iter->next==randomNode){
	        	check=0;
	        	return iter;
			}
			iter=iter->next;
			getPrev(randomNode);
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
		
		void insertionOfNewNodeByValue(){
			int value,key;
			cout<<"Enter key to search: ";
			cin>>key;
			cout<<"Enter value for new node: ";
			cin>>value;
			
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
				head=head->next;
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
			
			if(check==0){
				check++;
				iter=head;	
			}
			
			if(iter==NULL){
				check=0;
				return;
			}
			cout<<iter->value;
			if(iter->next!=NULL){
			}
			iter=iter->next;
			print();
		}
};
int main(){
	node *search;
	SinglyLinkedList ll;
	ll.createList();
	ll.createList();
	ll.createList();
	ll.print();
	search=ll.searching(2);
	ll.getPrev(search);
	
	
	system("pause");
	return 0;
}

