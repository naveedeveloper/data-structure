#include<iostream>
using namespace std;
const int SIZE=5;

int main(){
    int arr[]={2,5,7,8,9};
    int input;
    bool found=false;

    cout<<"Enter number to search : ";
    cin>>input;

    for(int i=0;i<SIZE;i++){
        if(arr[i] == input){
            found = true;
            break;
        }
    }

    if(found == true)
        cout<<"Found!!!"<<endl;
    else
        cout<<"Not found!!!"<<endl;
    
    return 0;
}