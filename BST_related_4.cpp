#include<iostream>
using namespace std;

struct node{
    int value,counter;
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
        int SBT(node*,int);
        int secondmax(node *temp);
        int thirdmax(node *temp);
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
    newNode->counter=1;
    return newNode;
}

void BST::insertion(node* temp){

    if(root==NULL){
        temp=createNode(value);
        root=temp;
        return;      
    }

    if(temp->value==value){
        temp->counter++;
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

int BST::SBT(node *temp,int num){
    if(temp == NULL) return 0;
    if(temp->value == num){
        return temp->counter;
    }{
        if(temp->left != NULL){
            return SBT(temp->left,num);
        }

        if(temp->right != NULL){
            return SBT(temp->right,num);
        }
    }

    return temp->counter;
}

int BST::secondmax(node *temp){
    if(temp==NULL) return 0;
    
    if(temp->right==NULL){
        if(temp->left!=NULL){
            return temp->left->value;
        }else{
            return 0;
        }
    }
    if(temp->right->right==NULL){
        return temp->value;
    }

    if(temp->right->right->right==NULL){
        return temp->right->value;
    }

    return secondmax(temp->right);

    return secondmax(temp->left);
}

int BST::thirdmax(node *temp){
    if(temp == NULL) return 0;

    if(temp->right == NULL){
        if(temp->left!=NULL){
            if(temp->left->left!=NULL){

            }
        }
    }
}

int main(){
    BST obj;
    int i=0,num;
    while(i<10){
        cout<<"Enter value please: ";
        cin>>obj.value;
        obj.insertion(obj.root);
        i++;
    }
    
    obj.inOrder(obj.root);
    //cout<<"\n Enter number : ";
    //cin>>num;
    //cout<<"\n Number of time a duplicate appeare in tree : "<<obj.SBT(obj.root,num)<<endl;
    cout<<"\n second max:"<<obj.secondmax(obj.root);
    return 0;
}
