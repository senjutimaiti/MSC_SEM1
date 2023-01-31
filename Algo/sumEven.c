#include<stdio.h>

int sum(int n){
	if(n == 0){
		return 0;
	}
	else{
		return n+sum(n-2);
	}
}

int main(){
	int n;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	int s = sum(2*n);
	printf("The sum of first %d even numbers is %d\n",n,s);
	return 0;
}
