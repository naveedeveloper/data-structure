//In this program, we are going to cover the Linked List data structure.
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int info;
    Node *next;
};

class Linked_List{
private:
    Node *head,*curr,*temp;
    int choice,key;
    bool val_found;
public:
    Linked_List();//Default Constructor
    int menu();
    Node* create_node(int);
    void create_list();
    void delete_node(int);
    void print();
};

Linked_List::Linked_List(){
    head = curr = temp = NULL;
    key = choice = 0;
    val_found = false;
}

int Linked_List::menu(){
    cout<<"1.create_list()"<<endl;
    cout<<"2.print()"<<endl;
    cout<<"3.delete_node()"<<endl;
    cout<<"Enter your choice(1,2,3) : ";
    cin>>choice;
    return choice;
}

//This function will make a new node for us
Node* Linked_List::create_node(int val){
    Node* newNode = new Node;
    newNode->info = val;
    newNode->next = NULL;
    return newNode;
}

//This Function will create Linked list
void Linked_List::create_list(){
    int val;
    cout<<"Enter value : ";
    cin>>val;
    if(head == NULL){
        curr = create_node(val);
        head = curr;
    }else{
        curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }

        temp  = curr;
        curr->next = create_node(val);
        curr = curr->next;
        temp->next = curr;
    }
}

void Linked_List::delete_node(int key){
    if(head == NULL){
        cout<<"Linked list is Empty!!!"<<endl;
    }else{
        if(head->info == key){
            if(head->next != NULL){
                head = head->next;
            }else{
                head = NULL;
                cout<<"List is Empty now!!!"<<endl;
            }
        }else{
            temp = head;
            while(temp != NULL){
                if(temp->next->info == key){
                    if(temp->next->next != NULL){
                        temp->next = temp->next->next;
                    }else{
                        temp->next = NULL;
                    }
                    break;
                }
                temp = temp->next;
            }
        }
    }
}

void Linked_List::print(){
    if(head == NULL){
        cout<<"List is Empty!!!"<<endl;
    }else{
        curr = head;
        while(curr != NULL){
            cout<<curr->info<<" ";
            curr = curr->next;
        }
    }
    cout<<endl;
}

int main(){
    Linked_List obj;
    int choice, key;
    char opt;
    
    do{
        choice = obj.menu();
        if(choice == 1){
            obj.create_list();
        }else if(choice == 2){
            obj.print();
        }else if(choice == 3){
            cout<<"Enter key to delete : ";
            cin>>key;
            obj.delete_node(key);
        }else{
            cout<<"Enter valid choice please!!!"<<endl;
        }
        cout<<"Do you want to continue(y,n)? ";
        cin>>opt;
    }while(opt != 'n');

    return 0;
}