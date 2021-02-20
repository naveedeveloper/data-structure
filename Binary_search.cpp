#include<iostream>
using namespace std;

bool binary_search(int arr[],int left,int right,int val){
    int mid;
    while(left<=right){
        mid = left + (right - left) / 2;
        
        if(arr[mid] == val){
            return true;
        }else if(arr[mid] < val){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return false;
}

int main(){
    int num;
    int arr[] = {1,2,3,5,7,65,345};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout<<"Enter value to search : ";
    cin>>num;
    
    cout<<binary_search(arr,0,size-1,num)<<endl;

    return 0;
}
