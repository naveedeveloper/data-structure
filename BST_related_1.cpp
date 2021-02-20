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
        void missingNumbers(node*);
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

void BST::missingNumbers(node *temp){
    if(temp == NULL){
        cout<<"tree is empty!!1"<<endl;
        return;
    }
    if(temp->right!=NULL){
    if((temp->value+1) != temp->right->value)
    {        cout<<endl<<"missing element between "<<temp->value<<" and  "<<temp->right->value<<" are: "<<endl;
        int num=temp->value;
        while(num+1 < temp->right->value){
            cout<<num+1<<" ";
            num++;
        }
        cout<<endl;
    }
}   
     missingNumbers(temp->right);

}

int main(){
    BST obj;
    int i=0;
    while(i<10){
        cout<<"Enter value please: ";
        cin>>obj.value;
        obj.insertion(obj.root);
        i++;
    }
    
    obj.inOrder(obj.root);
    obj.missingNumbers(obj.root);

    return 0;
}