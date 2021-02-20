#include<iostream>
#include<string>
using namespace std;
#define TABLE_SIZE 10

struct node{
    int data;
    node *next;
};

node *head[TABLE_SIZE] = {NULL},*current;

void insert(){
    int i,key;
    cout<<"Enter value to insert : ";
    cin>>key;
    i = key%TABLE_SIZE;

    node *newNode = new node;
    newNode->data = key;
    newNode->next = NULL;

    if(head[i] == NULL){
        head[i] = newNode;
    }else{
        current = head[i];
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}

void Search(){
    int key,index;

    cout<<"Enter value to be searched : ";
    cin>>key;

    index = key%TABLE_SIZE;
    if(head[index] == NULL){
        cout<<"Element not found!!!!"<<endl;
    }else{
        for(current = head[index];current!=NULL;current = current->next){
            if(current->data == key){
                cout<<"Search elemnt is found in thelist at index "<<index<<endl;
                break;
            }
        }

        if(current == NULL){
            cout<<"Search element not found!!!"<<endl;
        }
    }
}

void display(){

    for(int i=0;i<TABLE_SIZE;i++){
        cout<<endl;
        if(head[i] == NULL){
            continue;
        }else{
            for(current = head[i]; current != NULL ;current = current->next){
                cout<<current->data<<" ";
            }
            cout<<endl; 
        }
    }
}
int main(){
    int opt,key;
    while(1){
        cout<<"\n press \n 1)insert \n 2)Display \n 3)Search \n 4)Exit \n"<<endl;
        cin>>opt;
        
        switch(opt){
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                Search();
                break;
            case 4:
                exit(0);
        }
    }

    return 0;
}