#include<iostream>
using namespace std;

void reverse(char *ptr){
    if(*ptr=='\0'){
        cout<<endl;
        return;
    }else{
        cout<<*ptr;
        reverse(ptr+1);
        cout<<*ptr;
    }
}

int main(){
    char str[]="Hello World";
    reverse(str);
    cout<<endl;

    return 0;
}