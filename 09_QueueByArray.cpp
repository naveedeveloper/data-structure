#include<iostream>
using namespace std;

class Queue{
private:
	int *rear,*front,*arr,size,limit;
public:
	Queue(){
		cout<<"Enter the size of Queue: ";
		cin>>size;
		arr=new int[size];
		front=arr;
		rear=arr;
		limit=0;
	}
	
	void enQueue(){
		if(limit>size){
			cout<<"Queue overflow!!!"<<endl;
			return;
		}
		if(rear==arr+(size-1)){
			cout<<"Enter value please :";
			cin>>*(rear);
			rear=arr;
			limit++;
		}
		
		cout<<"Enter value please :";
		cin>>*(rear);
		rear++;
		limit++;
	}
	
	void deQueue(){
		if(limit==0){
			cout<<"Queue underflow!!!"<<endl;
			return;
		}
		if(front==arr+(size-1)){
			limit--;
			front=arr;
			return;
		}
		limit--;
		front++;
	}
	
	void print(){
		if(limit==0){
			cout<<"Queue underflow!!!"<<endl;
			return;
		}
		int *temp=front;
		for(int i=0;i<limit;i++){
			if(temp==arr+(size-1)){
				cout<<*(temp)<<" ";
				temp=arr;
			}
			cout<<*(temp)<<" ";
			temp++;
		}
		cout<<endl;
	}
};
int main(){
	Queue obj;
	obj.enQueue();
	obj.enQueue();
	obj.enQueue();
	obj.enQueue();
	obj.print();
//	obj.deQueue();
//	obj.deQueue();
//	obj.deQueue();
//	obj.print();
//	obj.enQueue();
//	obj.enQueue();
//	obj.enQueue();
//	obj.enQueue();
//	obj.print();
//	 
	
	system("pause");
	return 0;
}

