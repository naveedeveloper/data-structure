#include<iostream>
using namespace std;

struct node{
	int val;
	node *left,*right;
	bool Rth,Lth;
};

node *root;
void insert(node*,node*);
void create();
void inOrder(node*);

void create(){
	char ch;
	do{
		node *temp = new node;
		cout<<"Enter val for node : ";
		cin>>temp->val;
		temp->left = temp->right = NULL;
		temp->Lth = temp->Rth = false;

		if(root == NULL){
			root = temp;
			node *dummy = new node;
			dummy->val = 999;
			dummy->right = dummy;
			dummy->left = root;
			dummy->Lth = dummy->Rth = true;
			root->left = dummy;
			root->right = dummy;
		}else{
			insert(root,temp);
		}
		cout<<"Do you want to continue(y,n)??";
		cin>>ch;
	}while(ch == 'y');
}

void insert(node *root,node *temp){
	if(temp->val < root->val){
		if(root->left == NULL){
			root->left = temp;
			temp->left = root->left;
			temp->right = root;
			root->Lth = true;
		}else{
			insert(root->left,temp);
		}
	}

	if(temp->val > root->val){
		if(root->right == NULL){
			root->right = temp;
			temp->left = root;
			temp->right = root->right;
			root->Rth = true;
		}else{
			insert(root->right,temp);
		}
	}
}

void inOrder(node *iter){
	node *temp = iter->left;
	do{
		while(temp->Lth != false){
			temp = temp->left;
		}
		cout<<temp->val<<" ";
		while(temp->Rth == false){
			temp = temp->right;
			if(temp == iter)
				return;
			cout<<temp->val<<" ";
		}
		temp = temp->right;
	}while(temp != iter);
}

int main(){
	root = NULL;
	int i = 0;
	while(i < 10){
		create();
		i++;
	}

	inOrder(root);

	return 0;
}