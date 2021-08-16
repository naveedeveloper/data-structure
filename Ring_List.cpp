//In this program, we are going to cover the Ring Linked List(Singly) data structure.
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int info;
    Node *next;
};

class Ring_List{
private:
    Node *head,*curr,*temp;
    int choice,key;
public:
    Ring_List();//Default Constructor
    int menu();
    Node* create_node(int);
    Node* get_tail();
    void create_list();
    Node* searching(int);
    void delete_node();
    void print();
};

Ring_List::Ring_List(){
    head = curr = temp = NULL;
    key = choice = 0;
}

int Ring_List::menu(){
    cout<<"1.create_list()"<<endl;
    cout<<"2.print()"<<endl;
    cout<<"3.delete_node()"<<endl;
    cout<<"Enter your choice(1,2,3) : ";
    cin>>choice;
    return choice;
}

//This function will make a new node
Node* Ring_List::create_node(int val){
    Node* newNode = new Node;
    newNode->info = val;
    newNode->next = NULL;
    return newNode;
}

Node* Ring_List::get_tail(){
	temp = head;
	while(temp->next != head){
		temp = temp->next;
	}
    
	return temp;
}

//This Function will create Linked list
void Ring_List::create_list(){
    int val;
    cout<<"Enter value : ";
    cin>>val;
    if(head == NULL){
        curr = create_node(val);
        head = curr;
        head->next = head;
    }else{
        Node *tail = get_tail();
        curr = tail;
        curr->next = create_node(val);
        curr = curr->next;
        tail->next = curr;
        curr->next = head;
    }
}

Node* Ring_List::searching(int key){
	if(head == NULL){
		cout<<"List is empty!!"<<endl;
		return NULL;
	}
	
	temp = head;
    //In case of head(special case)
	if(head->info == key){
        return head;
    }

    bool found = false;
    do{
        //It is singly linked list, the only way to delete a node is from previous node
		if(temp->next->info == key){
            found = true;
			break;
		}
		temp = temp->next;
    }
	while(temp != head);

    if(found == false)
        return NULL;
    else
        return temp;
}

void Ring_List::delete_node(){
    if(head == NULL){
        cout<<"Linked list is Empty!!!"<<endl;
    }else{
        cout<<"Enter value to delete :";
        cin>>key;
        Node* search = searching(key);
        if(search == NULL){
            cout<<"value not found!!!"<<endl;
            return;
        }
        //In case of head node, We need to update the head
        if(search == head){
            if(head->next != head){
                Node *tail = get_tail();
                head = head->next;
                tail->next = head;
            }else{
                head = NULL;
            }
        }else{
            //if the search node is not head, it mean's that the search node is one node back from wanted node 
            temp = search->next;
            if(temp->next != head){
                search->next = temp->next;
            }else{
                search->next = head;
            }
            delete temp;
        }
    }
}

void Ring_List::print(){
    if(head == NULL){
        cout<<"List is Empty!!!"<<endl;
    }else{
        curr = head;
        do{
            cout<<curr->info<<" ";
            curr = curr->next;
        }
        while(curr != head);
    }
    cout<<endl;
}

int main(){
    Ring_List obj;
    int choice;
    char opt;
    
    do{
        choice = obj.menu();
        if(choice == 1){
            obj.create_list();
        }else if(choice == 2){
            obj.print();
        }else if(choice == 3){
            obj.delete_node();
        }else{
            cout<<"Enter valid choice please!!!"<<endl;
        }
        cout<<"Do you want to continue(y,n)? ";
        cin>>opt;
    }while(opt != 'n');

    return 0;
}