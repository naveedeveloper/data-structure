#include<iostream> 
using namespace std; 

struct node { 
	int key; 
	node *left, *right; 
}; 

node *newNode(int item) { 
	node *temp =new node; 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

node* insert(node* current, int key) { 
	if (current == NULL){
        return newNode(key);
    }  

	if (key == current->key) {
		cout<<"duplicate found!!!"<<endl; 
        return NULL; 
	} 

	if (key < current->key) 
		current->left = insert(current->left, key); 
	else
		current->right = insert(current->right, key); 

	return current; 
} 

bool isNumber(node *temp,int key){
    bool found = false;
    if(temp == NULL){
        return found;
    }else{
        if(temp->key == key){
            return found = true;
        }else if(key < temp->key){
            found = isNumber(temp->left,key);
        }else if(key > temp->key){
            found = isNumber(temp->right,key);
        }
    }
    return found;
}

int numberOFNodes(node *temp){
    int counter = 0;

    if(temp == NULL){
        return counter;
    }else{
        if(temp->left != NULL){
            counter = counter + numberOFNodes(temp->left);
        }

        if(temp->right != NULL){
            counter = counter + numberOFNodes(temp->right);
        }

        if(temp->left == NULL && temp->right == NULL){
            counter = counter + 1;
            return counter;
        }
    }
    return counter+1;
}

int max(node *iter){
    int val = 0;
    if(iter == NULL){
        cout<<"Tree is Empty!!!"<<endl;
        return val;
    }else if(iter->right == NULL){
        return iter->key;
    }else{
        if(iter->right != NULL){
            val = max(iter->right);
        }else{
            val = iter->key;
            return val;
        }
    }
    return val;
}

int min(node *iter){
    int val = 0;
    if(iter == NULL){
        cout<<"Tree is Empty!!!"<<endl;
        return val;
    }else if(iter->left == NULL){
        return iter->key;
    }else{
        if(iter->left != NULL){
            val = min(iter->left);
        }else{
            val = iter->key;
            return val;
        }
    }
    return val;
}

int Sum(node *temp){
    if(temp == NULL){
        return 0;
    }

    return (temp->key+Sum(temp->left)+Sum(temp->right));
}

int main(){ 

	node *root = NULL;
    int num; 
    /*
            50
           /  \
          25   75
        /   \    \
       22    40   85
                 /  \
                84   86

    */


	root = insert(root, 50); 
	root = insert(root, 25); 
	root = insert(root, 75); 
	root = insert(root, 22); 
	root = insert(root, 40);
    root = insert(root, 85);
    root = insert(root, 84); 
	root = insert(root, 86); 

    // cout<<"Enter number to search in tree:  ";
    // cin>>num;

    // cout<<"Answer : "<<isNumber(root,num)<<endl;
    // cout<<"The number of nodes in tree are  : "<<numberOFNodes(root)<<endl;
    // cout<<"The maximum number in tree is : "<<endl<<max(root)<<endl;
    // cout<<"The minimum number in tree is : "<<endl<<min(root)<<endl;
	// cout<<"The sum of Tree is : "<<Sum(root)<<endl;

    return 0; 
} 