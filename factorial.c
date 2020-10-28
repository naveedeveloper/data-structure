#include<stdio.h>
int main(){
	int num,fact=1,i;
	printf("Enter num to find its factorial :");
	scanf("%d",&num);
	
	if(num<0){
		printf("The factorial of negative numbers does not exist!!!");
		return;
	}
	
	for(i=num;i>0;i--){
		fact=fact*i;
	}
	
	printf("The factorial of %d is : %d \n",num,fact);
	
	return 0;
}
