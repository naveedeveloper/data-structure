#include<iostream>
#include<cmath>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

class CBT {

private:
	node* root;

public:
	CBT()
	{
		root = NULL;
	}

	node* Create(int data)
	{
		node* Node = new node();
		Node->data = data;
		Node->left == NULL;
		Node->right == NULL;
		return Node;
	}

	node* Get_Root()
	{
		return root;
	}

	void print(node* temp)
	{
		if (temp == NULL)
			return;
		cout << temp->data << " ";
		print(temp->left);
		
		print(temp->right);
	}

	int countnodes(node* temp)
	{
		int c = 0;
		if (temp == NULL)
		{
			return 0;
		}
		c = c + countnodes(temp->left);
		c = c + countnodes(temp->right);
		c++;
		return c;
	}

	int height(node* temp)
	{
		if (temp == NULL)
		{
			return 0;
		}
		int l = height(temp->left);
		int r = height(temp->right);
		if (l > r)
		{
			return(l + 1);
		}
		else
		{
			return(r + 1);
		}
	}
	void insert(node* temp, int data)
	{
		if (Get_Root() == NULL)
		{
			//cout<<endl<<"enter the value you want to insert";
		   // int data;
		   // cin>>data;
			root = Create(data);
			return;
		}
		int lefth = height(temp->left);
		int leftc = countnodes(temp->left);
		//cout<<endl<<countnodes(temp->left);
		int expected = pow(2, lefth) - 1;
		int rightc = countnodes(temp->right);
		if (leftc == rightc)
		{
			if (temp->left == NULL)
			{
				/* code */
			   // cout<<endl<<"enter the value you want to insert";
			  //  int data;
			  //  cin>>data;
				temp->left = Create(data);
				//return;
			}
			else
			{
				insert(temp->left, data);
			}
		}
		else if (expected > leftc)
		{
			if (temp->left == NULL)
			{
				// cout<<endl<<"enter the value you want to insert";
			   //  int data;
			   //  cin>>data;
				temp->left = Create(data);
				//return;
			}
			else
			{
				insert(temp->left, data);
			}
		}
		else if (temp->right == NULL)
		{
			// cout<<endl<<"enter the value you want to insert";
			 //int data;
			 //cin>>data;
			temp->right = Create(data);
			//return;
		}
		else
		{
			insert(temp->right, data);
		}

        
		if (temp->left != NULL)
		{
			if (temp->left->data > temp->data)
			{
				int x = temp->left->data;
				temp->left->data = temp->data;
				temp->data = x;
			}
		}
		if (temp->right != NULL)
		{
			if (temp->right->data > temp->data)
			{
				int x = temp->right->data;
				temp->right->data = temp->data;
				temp->data = x;
			}
		}
	}

};

int main()
{
	CBT b;
	b.insert(b.Get_Root(), 1);
	b.insert(b.Get_Root(), 2);
	b.insert(b.Get_Root(), 3);
	b.insert(b.Get_Root(), 4);
	b.insert(b.Get_Root(), 5);
	b.insert(b.Get_Root(), 6);
	b.insert(b.Get_Root(), 7);
	b.insert(b.Get_Root(), 8);
	b.insert(b.Get_Root(), 9);
	b.insert(b.Get_Root(), 10);
	b.insert(b.Get_Root(), 11);
	b.insert(b.Get_Root(), 12);
	b.insert(b.Get_Root(), 13);
	b.insert(b.Get_Root(), 14);
	b.print(b.Get_Root());

}