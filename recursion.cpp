#include<iostream>
using namespace std;
void recursion(int count){
	
	cout<<"usman"<<endl;
	if(count<=0){
		return;
	}
	return recursion(count-1);
}

int main(){
	
	recursion(5);
	system("pause");
	return 0;
}

