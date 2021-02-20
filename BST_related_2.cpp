#include<iostream>
using namespace std;

struct node{
    int value;
    node *left,*right;
};

class BST{
    private:
        node *temp;
        int key;
    public:
        node *root;
        int value;
        BST();
        node* createNode(int);
        void insertion(node*);
        void inOrder(node*);
        void range(node*,int,int);
};

BST::BST(){
    root=temp=NULL;
    value=key=0;
}

node* BST::createNode(int value){
    node *newNode=new node;
    newNode->value=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void BST::insertion(node* temp){

    if(root==NULL){
        temp=createNode(value);
        root=temp;
        return;      
    }

    if(temp->value==value){
        cout<<"Duplicate found!!!"<<endl;
        return;
    }

    if(value < temp->value){
        if(temp->left!=NULL){
           insertion(temp->left); 
        }else{
            temp->left=createNode(value);
        }
        return;
    }

    if(value > temp->value){
        if(temp->right!=NULL){
           insertion(temp->right); 
        }else{
            temp->right=createNode(value);
        }
        return;
    }
}

void BST::inOrder(node* temp){
    if(root==NULL){
        cout<<endl;
        cout<<"tree is empty!!!"<<endl;
        return;
    }

    if(temp->left!=NULL)
        inOrder(temp->left);
        cout<<temp->value<<" ";
    if(temp->right!=NULL)
        inOrder(temp->right);
    
    return;
}

void BST::range(node *temp,int start,int end){
    if(temp == NULL) return;

    if(start<end){
        if(temp->value>start && temp->value<end){
            cout<<temp->value<<" ";
        }

    }

    if(temp->left!=NULL)
        range(temp->left,start,end);
    if(temp->right!=NULL)
        range(temp->right,start,end);
    
}

int main(){
    BST obj;
    int i=0,start,end;
    while(i<10){
        cout<<"Enter value please: ";
        cin>>obj.value;
        obj.insertion(obj.root);
        i++;
    }
    
    obj.inOrder(obj.root);
    
    cout<<"Enter start : ";
    cin>>start;
    cout<<"Enter end: ";
    cin>>end;

    obj.range(obj.root,start,end);
    return 0;
}
