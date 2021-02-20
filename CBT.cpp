#include<iostream>
#include<cmath>
using namespace std;

struct node{
    int val;
    node *left,*right;
};

class CBT{
    public:
        node *root;
    
    CBT();
    node* createNode(int);
    int find_height(node*,int);
    int count_node(node*,int);
    void insertion(node*,int);
    node* find_node(node*,int);
    node* last_node(node*);
    void deletion(node*,int);
    void print(node*);
};

CBT::CBT(){
    root = NULL;
}

node* CBT::createNode(int value){
    node *newNode = new node;
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int CBT::find_height(node *temp,int ans=0){
    if(temp == NULL)
        return ans;
    
    if(temp->left != NULL)
        ans = ans+find_height(temp->left,ans++);
	
	if(temp->left == NULL){
		ans = 1;
		return ans;
	}

	return ans;
}

int CBT::count_node(node *temp,int count = 0){
    if(temp == NULL){
        return count;
    }

    if(temp->left != NULL)
        count += count_node(temp->left,count);

    if(temp->right != NULL)
        count += count_node(temp->right,count);

	if(temp->left == NULL && temp->right == NULL){
		return ++count;
	}
	
    return count;
}

void CBT::insertion(node *temp,int val){
    if(temp == NULL){
        temp = createNode(val);
        
        if(root == NULL) root = temp;
        return;
    }

    int height = find_height(temp->left);
    int expected_node = pow(height,2) - 1;
    int left_tree_count_node = count_node(temp->left);
    int right_tree_count_node = count_node(temp->right);

    if(left_tree_count_node == right_tree_count_node){
        temp->left = createNode(val);
    }else if(expected_node != left_tree_count_node){
        if(temp->left == NULL){
            temp->left = createNode(val);
            return;
        }else{
            insertion(temp->left,val);
        }
    }else if(temp->right == NULL){
        temp->right = createNode(val);    
        return;
    }else if(expected_node != right_tree_count_node){
        if(temp->right == NULL){
            temp->right = createNode(val);
            return;
        }else{
            insertion(temp->right,val);
        }
    }
}

node* CBT::find_node(node *temp,int key){
    if(temp == NULL){
        return NULL;
    }

    if(temp->val == key){
        return temp;
    }
    
    if(temp->left != NULL){
        return find_node(temp->left,key);
    }

    if(temp->right != NULL){
        return find_node(temp->right,key);
    }
    return temp;
}

node* CBT::last_node(node *temp){
    if(temp == NULL){
        return NULL;
    }

    if(temp->left == NULL && temp->right == NULL){
        return temp;
    }

    if(temp->right != NULL){
        return last_node(temp->right);
    }else if(temp->left != NULL){
        return last_node(temp->left);
    }

    return NULL;
}

void CBT::deletion(node* temp,int key){
    node *temp1 = find_node(temp,key);

    if(temp1 != NULL){
        node *last=last_node(temp);
        temp1->val = last->val;

        delete last;
    }

}

void CBT::print(node *temp){
    if(temp == NULL){
        return;
    }

    cout<<temp->val<<" ";
    if(temp->left != NULL)
        print(temp->left);
    if(temp->right != NULL)
        print(temp->right);
}

int main(){
    CBT cbt;
    cbt.insertion(cbt.root,1);
    cbt.insertion(cbt.root,2);
    cbt.insertion(cbt.root,3);
    cbt.insertion(cbt.root,4);
    cbt.insertion(cbt.root,5);
    cbt.insertion(cbt.root,6);
    cbt.insertion(cbt.root,7);

    cbt.print(cbt.root);
    cout<<endl;

    cbt.deletion(cbt.root,3);
    cout<<endl;
    cbt.print(cbt.root);
    return 0;
}