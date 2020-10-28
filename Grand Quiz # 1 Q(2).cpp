#include<iostream>
#include<string>
#include<cmath>
using namespace std;

struct node{
    string data;
    node* next;
};

class List{
    private:
        node *head;
    public:
        List(){
            head = NULL;
        }
    
    node * get_new_node(string data){
        node* link_node = new node();
        link_node->data=data;
        link_node->next=NULL;
        return link_node;
    }

    void add_link_node_to_head(string data){
		if(head==NULL){
            head = get_new_node(data);
            return;
        }
        node* data_node = get_new_node(data);
        data_node->next = head;
        head = data_node;
    }

    void add_link_node_to_tail(string data){
        if(head==NULL){
            head = get_new_node(data);
            return;
        }
       
        node* data_node = get_new_node(data);
        node *tail = get_tail(head);
        tail->next = data_node;
       
    }

    node* get_head(){
        return head;
    }

    node* get_tail(node* head){
        node* tail_hunter =head;
        while(tail_hunter->next!=NULL)
        tail_hunter = tail_hunter->next;
        return tail_hunter;
    }

    // Task solution

    string get_data(node* random_node){
        if (random_node==NULL)
            return 0;
        else return random_node->data;
    }

    node* get_prev(node* random_node){
        node* temp_iter = head;
        if (random_node==NULL)
                return NULL;
        if (random_node==head)return head;
        while(temp_iter->next!=random_node){
            temp_iter=temp_iter->next;
        }
        return temp_iter;
    }        

    void print(){
        node* itera = head;
        while(itera){
            cout<<itera->data<<" ";
            itera = itera->next;
        }
    }
    void min_max(){
    	node *iter=head;
    	int max,min;
    	max=0;
    
    	while(iter!=NULL){
    		if(max<iter->data.length()){
    			max=iter->data.length();
			}
			iter=iter->next;
        }
        
        iter=head;
        min=iter->data.length();
        while(iter!=NULL){
        	if(min>iter->data.length()){
        		min=iter->data.length();
			}
			iter=iter->next;
		}
		
		iter=head;
		while(iter!=NULL)
		{
			if(max==iter->data.length()){
				cout<<iter->data<<endl;
			}
			
			if(min==iter->data.length()){
				cout<<iter->data<<endl;	
				
			}
					iter=iter->next;
		}
	    return;
	}
};

int main(){
    List l1;
    // "devops aiopss bell in is"

    l1.add_link_node_to_tail("devops");
    l1.add_link_node_to_tail("aiopss");
    l1.add_link_node_to_tail("bell");
    l1.add_link_node_to_tail("in");
    l1.add_link_node_to_tail("is");
    l1.min_max();
   // l1.print();
    
    return 0;
}
