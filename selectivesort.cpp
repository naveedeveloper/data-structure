#include<iostream>
#include<string>
using namespace std;

void Swap(char &num1,char &num2){
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

void sort(char arr[],int size){
    for(int i=0;i<=(size-1);i++){
        for(int j=0;j<size;j++){
            if(int(arr[j]) > int(arr[i])){
                Swap(arr[i],arr[j]);
            }
        }
    }
}

void print(char arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    string myName = "Asim";
    char arr[myName.length()];

    for(int i=0 ;i<myName.length();i++){
        arr[i] = myName[i];
    }
    cout<<"list before sorting : ";
    print(arr,myName.length());
    
    sort(arr,myName.length());

    cout<<"list after sorting : ";
    print(arr,myName.length());

    return 0;
}