#include<iostream>
#include<string>
#include<cmath>
using namespace std;

struct node{
	char value;
	node *next;
};

class SinglyRingList{
	private:
		node *head;
	public:
		SinglyRingList(){
			head=NULL;
		}
		
		node* createNode(char data){
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

		void createList(char data){
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

		void print(){
			if(head==NULL){
				cout<<"List is empty!!!"<<endl;
				return;
			}
			
			node* iter=head;
			do{
				cout<<iter->value<<" -> ";
				iter=iter->next;
			}while(iter!=head);
			cout<<endl;
		}
		
		void numberOfWordsInList(){
		    node* iter=head;
		    int counter=1;
		    while(iter->next!=head){
		        if(iter->value==' '){
		            counter++;
		        }
		        iter=iter->next;
		    }
		    cout<<"The total number of words are : "<<counter<<endl;
		}
};
int main(){
	SinglyRingList ll;
	ll.createList('H');
	ll.createList('e');
	ll.createList('l');
	ll.createList('l');
	ll.createList('o');
	ll.createList(' ');
	ll.createList('h');
	ll.createList('o');
	ll.createList('w');
	ll.createList(' ');
	ll.createList('a');
	ll.createList('r');
	ll.createList('e');
	ll.createList(' ');
	ll.createList('y');
	ll.createList('o');
	ll.createList('u');
	ll.print();
	
	ll.numberOfWordsInList();
	system("pause");
	return 0;
}

