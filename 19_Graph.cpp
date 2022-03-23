#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct List{
    Node *node;
    List *down;
};

List *listHead = NULL;

void insertion(){
    int choice;
    cout<<"1)insert new Vertice"<<endl;
    cout<<"2)insert new egde "<<endl;
    cout<<"Enter your choice(1,2) : ";
    cin>>choice;

    if(choice == 1){
        if(listHead == NULL){
            List *temp = new List;
            cout<<"Enter value of Head vertex to insert : ";
            cin>>temp->node->data;
            temp->node->next = NULL;
            temp->down = NULL;
            listHead = temp;
            return;
        }else{
            List *list = listHead;
            while(list->down != NULL){
                list = list->down;
            }
            
            List *pre = list;
            list->down = new List;
            list = list->down; 
            cout<<"Enter value of vertex to insert : ";
            cin>>list->node->data;
            pre->down = list;
            list->down = NULL;
            list->node->next = NULL;
        }
    }else if(choice == 2){
        int vertex,edge;
        cout<<"Enter the vertex1 values: ";
        cin>>vertex;
        cout<<"Enter the vertex2 values: ";
        cin>>edge;

        List *list = listHead;
        bool found = false;
        while(list->down != NULL){
            if(list->node->data == vertex){
                found = true;
                break;
            }
            list = list->down;
        }
        
        if(found == false){
            cout<<"Vertex not found that you entered!!!"<<endl;
            return;
        }

        List *thisList = list;
        if(thisList->node->next == NULL){
            Node *node = new Node;
            node->data = edge;
            node->next = NULL;
            thisList->node->next = node;
        }else{
            Node *iter = thisList->node->next;
            while(iter->next != NULL){
                iter = iter->next;
            }

            Node *currentNode = iter;
            currentNode->data = edge;
            iter->next = currentNode;
            currentNode->next = NULL;
        }
    }else{
        cout<<"please choose the correct option!!!"<<endl;
    }
    return;
}

void print(){
    List *iter = listHead;
    while(iter->down != NULL){
        Node *current = iter->node;
        while(current != NULL){
            cout<<current->data<<" -> ";
            current = current->next;
        }
        cout<<endl;
        iter = iter->down;
    }
    cout<<endl;
}

int main(){
    int i = 0,n = 5;
    while(i < n){
        insertion();
        i++;
    }

    print();


    return 0;
}
