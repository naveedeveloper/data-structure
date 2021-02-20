#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};

class BST{
public:
    Node *root;
    BST();
    Node* newNode(int);
    void insertion(Node*,int);
    Node* deletion(Node*,int);
    void print(Node*);
    bool isNumber(Node*,int);
    int sum_of_tree(Node*);
    int number_of_leafs(Node*);
    int sum_of_leafs(Node*);
    int largest(Node*);
    int smallest(Node*);
    int height(Node*);
};

BST::BST(){
    root = NULL;
}

Node* BST::newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void BST::insertion(Node *temp,int val){
    if(root == NULL){
        temp = newNode(val);
        root = temp;
        return;
    }

    if(val < temp->data){
        if(temp->left == NULL){
            temp->left = newNode(val);
            return;
        }else{
            insertion(temp->left,val);
        }
    }

    if(val > temp->data){
        if(temp->right == NULL){
            temp->right = newNode(val);
            return;
        }else{
            insertion(temp->right,val);
        }
    }
}

Node* BST::deletion(Node* iter, int key){
    if (root == NULL){
        return root;
    }
 
    if (key < iter->data){
        iter->left = deletion(iter->left, key);
    }else if (key > iter->data){
        iter->right = deletion(iter->right, key);
    }else{
        // node with only one child or no child
        if(iter->left == NULL) {
            Node* temp = iter->right;
            delete iter;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = iter->left;
            delete iter;
            return temp;
        }
 
        // node with two children: Get the inorder successor
        Node *successor = iter->right;

        while(iter && iter->left != NULL){
            iter = iter->left; 
        }
 
        // Copy the inorder successor's content to this node
        successor->data = iter->data;
 
        // Delete the inorder successor
        iter->right = deletion(iter->right, iter->data);
    }
    return iter;
}

bool BST::isNumber(Node* temp,int key){
    if(temp == NULL){
        return false;
    }

    if(key < temp->data){
        return isNumber(temp->left,key);
    }else if(key > temp->data){
        return isNumber(temp->right,key);
    }else{
        return true;
    }
}

int BST::sum_of_tree(Node* temp){
    int sum = 0;
    if(root == NULL){
        return 0;
    }

    if(temp->left != NULL){
        sum += sum_of_tree(temp->left);
    }
    
    if(temp->right != NULL){
        sum += sum_of_tree(temp->right);
    }

    if(temp != NULL){
        sum += temp->data;
        return sum;
    }

    return sum;
}

int BST::number_of_leafs(Node *temp){
    int counter = 0;
    if(temp == NULL){
        return 0;
    }

    if(temp->left != NULL){
        counter += number_of_leafs(temp->left);
    }

    if(temp->right != NULL){
        counter += number_of_leafs(temp->right);
    }

    if(temp->left == NULL && temp->right == NULL){
        counter += 1;
        return counter;
    }

    return counter;
}

int BST::sum_of_leafs(Node *temp){
    int sum = 0;

    if(temp == NULL){
        return 0;
    }

    if(temp->left != NULL){
        sum += sum_of_leafs(temp->left);
    }

    if(temp->right != NULL){
        sum += sum_of_leafs(temp->right);
    }

    if(temp->left == NULL && temp->right == NULL){
        sum += temp->data;
        return sum;
    }

    return sum;
}

int BST::largest(Node* temp){
    int max = 0;
    if(temp == NULL){
        return max;
    }

    if(temp->left != NULL){
        max  = largest(temp->left);
    }
    
    if(temp->right !=  NULL){
        max = largest(temp->right);
    }
    
    if(max < temp->data){
        max = temp->data;
        return max;
    }

    return max;
}

int BST::smallest(Node* temp){
    int min = 0;
    if(temp == NULL){
        return 0;
    }

    if(temp->left != NULL){
        min = smallest(temp->left);
    }else{
        min = temp->data;
        return min;
    }
    return min;
}

void BST::print(Node* iter){
    if(iter == NULL){
        return;
    }

    if(iter->left != NULL){
        print(iter->left);
    }

    cout<<iter->data<<" ";

    if(iter->right != NULL){
        print(iter->right);
    }
}

int BST::height(Node * temp){
    if(temp == NULL){
        return 0;
    }else{
        int left_height = height(temp->left);
        int right_height = height(temp->right);

        if(left_height > right_height){
            return (left_height+1);
        }else{
            return (right_height+1);
        }
    }
}
int main(){
    int val;
    BST bst;

    bst.insertion(bst.root,40);
    bst.insertion(bst.root,35);
    bst.insertion(bst.root,20);
    bst.insertion(bst.root,38);
    bst.insertion(bst.root,55);
    bst.insertion(bst.root,45);
    bst.insertion(bst.root,65);

    cout<<endl;
    bst.print(bst.root);
    cout<<endl;
    
    // cout<<"Enter Number to search in tree : ";
    // cin>>val;
    // cout<<bst.isNumber(bst.root,val)<<endl;
    // cout<<"Sum of Tree : "<<bst.sum_of_tree(bst.root)<<endl;
    // cout<<"Number of leafs in this tree are :  "<<bst.number_of_leafs(bst.root)<<endl;
    // cout<<"Sum of leafs in this tree is :  "<<bst.sum_of_leafs(bst.root)<<endl;
    // cout<<"The maximum number in this tree is :  "<<bst.largest(bst.root)<<endl;
    // cout<<"The minimum number in this tree is :  "<<bst.smallest(bst.root)<<endl;
    cout<<"Hight : "<<bst.height(bst.root)<<endl;
    
    return 0;
}