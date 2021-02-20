#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
void word(char *ptr){
    if(*ptr=='\0' || *ptr==' '){
        cout<<" ";
        return;
    } 
    else{
        cout<<*ptr;
        word(ptr+1);
    }
}

void reverse(char *ptr){
    if(*ptr=='\0') return;
    reverse(ptr+1);
    if(*ptr==' '){
        word(ptr+1);
    }
}

int main(){
    string arr=" it is rainy day";
    reverse(&arr[0]);

    return 0;
}
