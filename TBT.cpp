#include<iostream>
using namespace std;
struct node {
    int data;
    node* left;
    node* right;
    int leftthread;
    int  rightthrrad;
};
class TBT {

    node* temp;
    node* dummy;
public:
    TBT() {
        temp = NULL;
        dummy = dummy;
        root = NULL;
    }

    node* root;
    node* find_min(node* root)
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root;
    }
    node* find_max(node* iter)
    {
        while (iter->right != NULL)
        {
            root = root->right;
        }
        return iter;
    }
    node* pre_node(node* root, int data)
    {
        if (root == NULL)
            return NULL;
        if (data > root->data)
        {
            if (root->right->data == data)
            {
                return root;
            }
            return pre_node(root->right, data);
        }
        if (data < root->data)
        {
            if (root->left->data == data)
            {
                return root;
            }
            return pre_node(root->left, data);
        }
        return NULL;
    }
    node* ancestors_rightnode(node* start, int data)
    {
        node* check;
        if (data > start->data)
        {
            return   ancestors_rightnode(start->right, data);
        }
        if (data < start->data)
        {
            check = ancestors_rightnode(start->left, data);
            if (check == NULL)
                return start;
            else return check;
        }
        return NULL;
    }
    node* ancestors_leftnode(node* start, int data)
    {

        node* check;
        if (data > start->data)
        {
            check = ancestors_leftnode(start->right, data);
            if (check == NULL)
                return start;
            else return check;
        }
        if (data < start->data)
        {
            return ancestors_leftnode(start->left, data);
        }
        return NULL;
    }
    node* inoreder_sucessor(node* temp)
    {

        /*if(temp->right!=dummy)
        {
     return find_min(temp->right);
        }*/
        node* parent = pre_node(root, temp->data);
        if (parent->left == temp)
        {
            return parent;
        }
        if (parent->right == temp)
        {
            return ancestors_rightnode(root, temp->data);

        }
        return NULL;
    }
    node* pre_Sucerssor(node* temp)
    {

        if (temp->left != dummy)
        {
            return  find_max(temp->left);
        }
        node* parent_node = pre_node(root, temp->data);
        if (parent_node->right == temp)
        {
            return parent_node;
        }
        if (parent_node->left == temp)
        {
            if (temp->right != dummy)
            {
                return find_min(temp->right);
            }
            return ancestors_leftnode(root, temp->data);
        }
        return NULL;
    }

    node* create_node(int data)
    {
        node* temp = new node;
        temp->data = data;
        temp->left = dummy;
        temp->right = dummy;
        temp->leftthread = 1;
        temp->rightthrrad = 1;
        return temp;
    }
    void threading(node* temp2)
    {
        node* ptr, * ptr1;
        ptr = inoreder_sucessor(temp2);
        ptr1 = pre_Sucerssor(temp2);
        if (ptr != NULL)
            temp2->right = ptr;
        if (ptr1 != NULL)
            temp2->left = ptr1;
        return;
    }
    void insertion(node* temp, int data)
    {
        if (root == NULL)
        {
            root = create_node(data);
            return;
        }
        if (temp->data > data)
        {
            if (temp->leftthread != 1)
            {
                insertion(temp->left, data);
            }
            else
            {

                temp->left = create_node(data);
                temp->leftthread = 0;
                threading(temp->left);
                return;
            }
        }
        else  if (temp->data < data)
        {
            if (temp->rightthrrad != 1)
            {
                insertion(temp->right, data);

            }
            else
            {
                temp->right = create_node(data);
                temp->rightthrrad = 0;
                threading(temp->right);
                return;
            }
        }
    }
    void print(node* iter)
    {

        cout << iter->data << endl;
        if (iter->right != dummy && iter->rightthrrad != 1)
            print(iter->right);
        if (iter->left != dummy && iter->leftthread != 1)
            print(iter->left);
    }
};
int main()
{
    TBT tree;
    tree.insertion(tree.root, 5);
    tree.insertion(tree.root, 8);
    tree.insertion(tree.root, 10);
    tree.insertion(tree.root, 7);
    tree.insertion(tree.root, 4);
    tree.insertion(tree.root, 3);
    tree.insertion(tree.root, 2);
    //tree.print(tree.root);
    cout << tree.root->right->right->left->data;

}