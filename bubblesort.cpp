#include<iostream>
using namespace std;

void bubblesort(int arr[],int size){
    int limit1 = size;
    int limit2 = limit1-1;

    for(int i=0;i<limit1;i++){
        for(int j=0;j<limit2;j++){
            if(arr[j] > arr[j+1]){
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        limit1--;
    }
}

int main(){
     int size=5;
    int arr[]={4,10,8,3,2};
    
    cout<<"list before sorting : ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl; 
    
    bubblesort(arr,size);

    cout<<"list after sorting : ";
    for(int j=0;j<size;j++){
        cout<<arr[j]<<" ";
    }
    cout<<endl;

    return 0;
}