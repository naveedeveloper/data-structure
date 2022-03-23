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
        void options();
        void insertion(node*);
        void deletion(node*,node*,int);
        void inOrder(node*);
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

void BST::options(){
    cout<<"//////////OPTIONS///////"<<endl;
    cout<<"1-insertion()"<<endl;
    cout<<"2-deletion()"<<endl;
    cout<<"3-inOrder()"<<endl;
    cout<<endl;
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

void BST::deletion(node *leafNode, node* parent, int key){
    //if tree is empty
    if(leafNode==NULL){
        cout<<"tree is empty!!!"<<endl;
        return; // important to return
    }
    
    node* currentParent = leafNode;

    if(key < leafNode->value) {
    	return deletion(leafNode->left, currentParent, key); // important to return
    }

    if(key > leafNode->value) {
    	return deletion(leafNode->right, currentParent, key); // important to return
    }
    
    // if program flow reaches here, it means we found the leafNode we want to delete
	//case 1:node deletion, incase, left & right leaf nodes are NULL
    if(leafNode->right==NULL && leafNode->left==NULL){
        if(parent != NULL) {
            if(parent->left == leafNode) parent->left = NULL;
            else parent->right = NULL;
        }
        
        delete leafNode;
        leafNode=NULL;
        return; //important to return the flow
    }

    //case 2:node having one child either left or right
    if(leafNode->left!=NULL && leafNode->right == NULL){
        parent->left = leafNode->left;
        leafNode->left = NULL;
        delete leafNode;
        return; //important to return the flow
    }

    if(leafNode->right!=NULL && leafNode->left == NULL){
        parent->right = leafNode->right;
        leafNode->right = NULL;
        delete leafNode;
        return; //important to return the flow
    }

    //case 3:node having 2 childs (simply move to right node, then traverse to the left most node from there and move it to leaf node location)
    node* deleteNode=leafNode;
    deleteNode = leafNode->right;

    while(deleteNode->left != NULL) {
        currentParent = deleteNode;
    	deleteNode = deleteNode->left;
    }
    // replace the value of deleteNode with leafNode & then delete deleteNode
    leafNode->value = deleteNode->value;
    
    delete deleteNode;
    deleteNode = NULL;
    currentParent->left = NULL;
}

int main(){
    BST obj;
    int choice;
    int key;
    
    do{
        obj.options();
        cout<<"Enter your choice : ";
        cin>>choice;

        if(choice==1){
            cout<<"Enter number to insert: ";
            cin>>obj.value;
            obj.insertion(obj.root);
        }else if(choice==2){
            cout<<"Enter key: ";
            cin>>key;
            obj.deletion(obj.root,NULL, key);
        }else if(choice==3){
            obj.inOrder(obj.root);
        }else{
            exit(0);
        }
    }while(4);

    return 0;
}
