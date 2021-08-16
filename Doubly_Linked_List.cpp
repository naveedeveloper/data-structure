//In this program, we are going to cover the Doubly Linked List data structure.
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int info;
    Node *next,*pre;
};

class Doubly_Linked_List{
private:
	Node *head,*temp;
	int value,choice;		
public:	
	Doubly_Linked_List();		
	Node* create_node(int);
	Node* get_tail(); 
	void create_list();
	Node* searching(int);
	void delete_node();
    int menu();
	void print();
};

Doubly_Linked_List::Doubly_Linked_List(){
	head = temp = NULL;
	value = choice = 0;
}

Node* Doubly_Linked_List::create_node(int val){
	Node *newNode = new Node;
	newNode->info = val;
    newNode->next = newNode->pre = NULL;
    return newNode; 
}

Node* Doubly_Linked_List::get_tail(){
	temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	return temp;
}

void Doubly_Linked_List::create_list(){
	cout<<"Enter value : ";
	cin>>value;
			
	if(head == NULL){
        head = create_node(value);
		return;
	}
            
	Node *tail = get_tail();
	Node *newnode = create_node(value);
	newnode->next = NULL;
	newnode->pre = tail;
	tail->next = newnode;
}

Node* Doubly_Linked_List::searching(int key){
	if(head == NULL){
		cout<<"list is empty :"<<endl;
		return NULL;
	}
	
	temp = head;
	while(temp != NULL){
		if(temp->info == key){
			break;
		}
		temp = temp->next;
	}
	return temp;
}

void Doubly_Linked_List::delete_node(){
	if(head == NULL){
		cout<<"List is empty : "<<endl;
	}
			
	temp = head;
	cout<<"Enter key to delete : ";
	cin>>value;

    Node *search = searching(value);
    Node *del = NULL;
    if(search == head){
        del = head;
		if(head->next == NULL){
			head = NULL;
			cout<<endl<<"List is Empty Now!!!"<<endl;
		}else{
			head = head->next;
			head->pre = NULL;
		}
    }else{
        del = search;
		temp = search;
        temp = temp->pre;
		if(search->next == NULL){
			temp->next = NULL;
		}else{
			temp->next = search->next;
			search->next->pre = temp;
		}
    }

	delete del;
}

void Doubly_Linked_List::print(){
	if(head == NULL){
		cout<<"List is empty!!!"<<endl;
		return;
	}
		
	temp = head;
	cout<<" [ "; 
	while(temp != NULL){
		cout<<temp->info;
		if(temp->next != NULL){
			cout<<" -> ";
		}
		temp=temp->next;
	}
	cout<<" ] "<<endl;
}

int Doubly_Linked_List::menu(){
    cout<<"1.create_list()"<<endl;
    cout<<"2.delete_node()"<<endl;
    cout<<"3.print()"<<endl;
    cout<<"Enter your choice(1,2,3) : ";
    cin>>choice;
    return choice;
}

int main(){
    Doubly_Linked_List obj;
    int choice;
    char opt;
    
    do{
        choice = obj.menu();
        if(choice == 1){
            obj.create_list();
        }else if(choice == 2){
            obj.delete_node();
        }else if(choice == 3){
            obj.print();
        }else{
            cout<<"Enter valid choice please!!!"<<endl;
        }
        cout<<"Do you want to continue(y,n)? ";
        cin>>opt;
    }while(opt != 'n');

    return 0;
}