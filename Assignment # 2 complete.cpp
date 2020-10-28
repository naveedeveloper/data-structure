#include<iostream>
using namespace std;
struct node{
	int value;
	node *next;
};

class LinkedList{
private:
	node *head;
	node *temp;
	int total;
public:
	LinkedList(){
		this->head=NULL;
		this->temp=NULL;
		this->total=0;
	}
	
	void insertion() {
        	int value;
            node* newNode = new node;
            cout<<"Enter a value:";
            cin>>value;
            newNode->value = value;
            newNode->next = NULL;
            
            if(this->head == NULL) {
                this->head = newNode;
                this->total++;
                return;
            }
            
            node* temp = this->head;
            
            int position;
            cout<<"\n0 - for head position\n";
            cout<<this->total<<" - for tail position";
            
            if(this->total > 1) {
                cout<<"\n[1-"<<this->total-1<<"] - for any position";
            }
            
            cout<<endl;
            cout<<"Enter position for the new node:";
            cin>>position;
            
            if(position > this->total) {
                cout<<"You entered incorrect position"<<endl;
                return;
            }
            
            if(position == 0) {
                this->head = newNode;
                this->head->next = temp;
                this->total++;
                return;
            }
            
            if(position == this->total) {
                while(temp->next != NULL) {
                    temp = temp->next;
                }
                
                temp->next = newNode;
                this->total++;
                return;
            }
            
            int index = 0;
            while(index++ < position-1) {
                temp = temp->next;
            }
            
            newNode->next = temp->next;
            temp->next = newNode;
            this->total++;
        }
    
	
	void deletion(){
		int key;
		
	 	this->temp=this->head;
		if(head==NULL){
			cout<<"No element entered yet!!!"<<endl;
			return;
		}
		cout<<"Enter key : ";
		cin>>key;
		if(key==this->head->value){
			this->head=this->temp->next;
			return;
		}	
		while(this->temp!=NULL){		
		if(this->temp->next->value==key){
			this->temp->next=this->temp->next->next;
			return;
	    }
		}
	}

	void search(){
		int key;
		bool found=false;
		
		this->temp=this->head;
		if(head==NULL){
			cout<<"No element entered yet!!!"<<endl;
			return;
		}
		cout<<"Enter key : ";
		cin>>key;
		while(this->temp!=NULL){		
		if(this->temp->value==key){
			found=true;
			return;
	    }
	    temp=temp->next;
		}
		
		if(found==true){
			cout<<key<<" is found in Linked list "<<endl;
		}else{
			cout<<key<<" is not found"<<endl;
		}
	}

	void emptiness(){
		if(this->head==NULL){
			cout<<"List is empty!!!"<<endl;
		}else{
			cout<<"List is not empty!!!"<<endl;
		}
	}

	void print(){
		if(this->head==0){
			cout<<"List is empty yet!!!"<<endl;
			return;
		}
		node *temp;
		temp=this->head;
		while(temp!=NULL){
			cout<<temp->value<<" ";
			temp=temp->next;
		}
	}
};
int main(){
	LinkedList ll;
	int choice;
	while(true){
		cout<<"\n-----Menu------\n 1 - insertion() \n 2 - print() \n 3 - Deletion() \n 4 - search() \n 5 - emptiness() \n any other number to exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		if(choice==1){
			ll.insertion();
		}else if(choice==2){
			ll.print();	
		}else if(choice==3){
			ll.deletion();
		}else if(choice==4){
			ll.search();
		}else if(choice==5){
			ll.emptiness();
		}else
		break;
		
	}
	return 0;
}
