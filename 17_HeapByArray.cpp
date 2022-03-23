#include<iostream>
using namespace std;
void Heapify(int arr[],int size,int i){
    int largest = i;
    int left_child = 2*i + 1;
    int right_child = 2*i + 2;

    if(left_child < size && arr[left_child] > arr[largest]){
        largest = left_child;
    }

    if(right_child < size && arr[right_child] > arr[largest]){
        largest = right_child;
    }

    if(largest != i){
        swap(arr[i],arr[largest]);

        Heapify(arr,size,largest);
    }
}

void bulid_Heap(int arr[],int size){
    int last_non_leaf_node = (size/2) - 1;

    for(int i = last_non_leaf_node;i >= 0 ; i--){
        Heapify(arr,size,i);
    }
}

void deleteRoot(int arr[], int& size){ 
    int last_node = arr[size - 1]; 
  
    arr[0] = last_node; 
  
    last_node = last_node - 1; 
   
    Heapify(arr, last_node, 0); 
} 

void insertNode(int arr[], int& size, int Key){ 
    size = size + 1; 
  
    arr[size - 1] = Key; 
  
    Heapify(arr, size, size - 1); 
}

void print(int arr[],int size){
    for(int i = 0 ;i < size ; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {5,7,8,3,2,9,6};

    int size_of_arr = sizeof(arr) / sizeof(arr[0]);

    cout<<"Array Representation : ";
    print(arr,size_of_arr);

    bulid_Heap(arr,size_of_arr);

    cout<<"Array represenatation of Heap is :  ";
    print(arr,size_of_arr);
    
    insertNode(arr,size_of_arr,100);

    cout<<"Array represenatation of Heap is :  ";
    print(arr,size_of_arr);

    return 0;
}
