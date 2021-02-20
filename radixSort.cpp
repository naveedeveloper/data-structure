#include<iostream>
using namespace std;

int getMax(int arr[],int size){
    int max = arr[0];
    for(int i=0;i<size;i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[],int size,int div){
    int output[size];   //for output like how many passes are we used
    int count[10] = {0}; 

    for(int i=0;i<size;i++){
        count[(arr[i]/div)%10]++;
    }

    for(int i=1;i<10;i++){
        count[i] += count[i -1];
    }

    for(int i=size-1;i>=0;i--){
        output[count[(arr[i]/div%10)] - 1] = arr[i];
        count[(arr[i]/div)%10]--;
    }

    for(int i=0;i<size;i++){
        arr[i] = output[i];
    }   
}

void RadixSort(int a[],int size){
    int max = getMax(a,size);

    for(int div=1;max/div>0;div*=10){
        countingSort(a,size,div);
    }
}

int main(){
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;
    int arr[size];

    cout<<"Enter "<<size<<" element in an array : ";

    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    cout<<endl<<"Before Sorting!!!"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    RadixSort(arr,size);

    cout<<endl<<"After Sorting!!!"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}