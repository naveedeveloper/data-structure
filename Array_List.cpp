//In this program we are going to cover the Array_list data structure.

#include<bits/stdc++.h>
using namespace std;

class Array_List{
private:
    int *str,*curr;
    int size,choice;
public:
    Array_List();//Constructor
    int menu();
    void create_list();
    void tail();
    void update(int,int);//to update the given index value
    void add(int,int);//This function will add new block/chank of memory at given index in the list
    void remove(int);//This function will remove a chank of memory of given index from the list
    void print();
};

Array_List::Array_List(){
    str = curr = NULL;
    size = choice = 0;
}

int Array_List::menu(){
    cout<<"1.create_list()"<<endl;
    cout<<"2.print()"<<endl;
    cout<<"3.update()"<<endl;
    cout<<"4.add()"<<endl;
    cout<<"5.remove()"<<endl;
    cout<<"Enter your choice(1,2,3,4,5) : ";
    cin>>choice;
    return choice;
}

void Array_List::create_list(){
    cout<<"Enter the size of an array : ";
    cin>>size;

    str = new int[size];
    curr = str;
    cout<<"Enter "<<size<<" values : "<<endl;
    for(int  i = 0;i < size;i++){
        cin>>*curr;
        curr++;
    }
}

void Array_List::tail(){
    curr = str;
    for(int i = 0;i < size;i++){
        curr++;
    }
}

void Array_List::print(){
    if(str == NULL){
        cout<<"List is Empty!!!"<<endl;
    }else{
        cout<<"Array List : ";
        curr = str;
        cout<<" [ ";
        for(int  i = 0;i < size;i++){
            cout<<*curr;
            if(i + 1 != size){
                cout<<" , ";
            }
            curr++;
        }
        cout<<" ] "<<endl;
    }
}

void Array_List::update(int index,int val){
    if(index < 0 || index > size){
        cout<<"Invalid Index!!"<<endl;
    }else{
        curr = str;
        for(int  i = 0;i < size;i++){
            if(i == index){
                *curr = val;
                break;
            }
            curr++;
        }
    }
}

void Array_List::add(int index,int val){
    if(index < 0 || index > size + 1){
        cout<<"Invalid Index!!!"<<endl;
    }else{
        size++;//add new chank
        tail();//Move curr pointer at the tail of the list 
        for(int i = size;i >= 0;i--){
            if(i > index){
                *curr = *(curr - 1);
            }else if(i == index){
                *curr = val;
                break;
            }
            curr--;
        }
    }
}

void Array_List::remove(int index){
    if(index < 0 || index > size){
        cout<<"Invalid Index!!"<<endl;
    }else{
        curr = str;
        for(int i = 0;i < size;i++){
            if(i >= index){
                *curr = *(curr + 1);
            }
            curr++;
        }
        size--;//Remove the last chank
    }
}

int main(){
    Array_List obj;
    int choice,index,val;
    char opt;
    
    do{
        choice = obj.menu();
        if(choice == 1){
            obj.create_list();
        }else if(choice == 2){
            obj.print();
        }else if(choice == 3){
            cout<<"Enter index please : ";
            cin>>index;
            cout<<"Enter value to update : ";
            cin>>val;
            obj.update(index,val);
        }else if(choice == 4){
            cout<<"Enter index please : ";
            cin>>index;
            cout<<"Enter value to add : ";
            cin>>val;
            obj.add(index,val);
        }else if(choice == 5){
            cout<<"Enter index please : ";
            cin>>index;
            obj.remove(index);
        }else{
            cout<<"Enter valid choice please!!!"<<endl;
        }
        cout<<"DO you want to continue(Y,N)? ";
        cin>>opt;
    }while(opt != 'N');

    return 0;
}