#include<iostream>
using namespace std;
const int SIZE=5;

class ArrayList{
private:
	int *ptr;
public:
	ArrayList(){
		ptr=NULL;
	}
	
	void creatList(){
		ptr=new int[SIZE];
	}
	
	void inputOfArray(){
		int *temp=NULL;
		temp=ptr;
		cout<<"Enter "<<SIZE<<" values: ";
		for(int i=0;i<SIZE;i++){
			cin>>*temp;
			temp++;
		}
		
	}
	
	void displayTheArray(){
		int *temp=NULL;
		temp=ptr;
		cout<<"The element of array are: ";
		for(int i=0;i<SIZE;i++){
			cout<<*temp<<" ";
			temp++;
		}
		cout<<endl;
	}
	
	void clear(){
			delete ptr;
	}
	
	int get(int index){
		int *temp=NULL;
		temp=ptr;
		int value;
		for(int i=0;i<SIZE;i++){
			if(i==index){
				value=*temp;
				return value;
			}
			temp++;
		}
	}
	
	void update(int value,int index){
		int *temp=NULL;
		temp=ptr;
		for(int i=0;i<SIZE;i++){
			if(i==index){
				*temp=value;
			}
			temp++;
		}
	}
	
	void find(int value){
		int *temp=NULL;
		temp=ptr;
		bool found=false;
		for(int i=0;i<SIZE;i++){
			for(int i=0;i<SIZE;i++){
				if(*temp==value){
					found=true;
				}
				temp++;
			}
		}
		if(found==true)
		cout<<value<<"is found in the array"<<endl;
		else
		cout<<value<<"is not found in the array"<<endl;
	}
};

int main(){
	ArrayList obj;
	int value,index;
	
	cout<<"creating "<<SIZE<<" element of array..."<<endl;
	obj.creatList();
	obj.inputOfArray();
	obj.displayTheArray();
	cout<<"Enter the index which value you want: ";
	cin>>index;
	cout<<index<<" index have the value "<<obj.get(index)<<endl;
	cout<<"Enter the value to update: ";
	cin>>value;
	cout<<"Enter the index at which you want to update the "<<value<<" : ";
	cin>>index;
	obj.update(value,index);
	cout<<endl;
	obj.displayTheArray();
	cout<<"Enter the value to find: ";
	cin>>value;
	obj.find(value);
	cout<<endl;
	cout<<"clearing the Array...."<<endl;
	obj.clear();
	
	return 0;
}


