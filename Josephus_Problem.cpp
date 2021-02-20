#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class RLL{
public:
    Node *head,*temp;
    RLL();
    Node* create_node(int);
    void insertion(int);
    void print();
    void josephus(int);
};

RLL::RLL(){
    this->head = NULL;
}

Node* RLL::create_node(int val){
    Node* node = new Node;
    node->data = val;
    node->next = NULL;
    return node;
}

void RLL::insertion(int val){
    if(head == NULL){
        head = create_node(val);
        head->next = head;
        return;
    }

    temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    Node* last = temp;
    temp->next = create_node(val);
    temp = temp->next;
    last->next = temp;
    temp->next = head;
}

void RLL::print(){
    if(head == NULL){
        cout<<"Linked list is empty!!"<<endl;
        return;
    }

    temp = head;

    do{
        cout<<temp->data;
        if(temp->next != head){
            cout<<" -> ";
        }
        temp = temp->next;
    }while(temp != head);

    cout<<endl;
}

void RLL::josephus(int jump){
    if(head == NULL){
        return;
    }

    temp = head;
    Node *del = head->next;

    while(head->next != head){
        for(int i = 1; i < jump ;i++){
            temp = temp->next;
            del = del->next;
        }
        cout<<"( "<<del->data<<" out ) "<<endl;
        temp->next = del->next;

        if(del = head){
            head = head->next;
        }
        delete del;
        temp = temp->next;
        del = temp->next;
    }
    cout<<"The winner is : "<<head->data<<endl;
}

int main(){
    RLL rll;

    rll.insertion(1);
    rll.insertion(2);
    rll.insertion(3);
    rll.insertion(4);
    rll.insertion(5);

    rll.print();

    rll.josephus(3);

    return 0;
}
