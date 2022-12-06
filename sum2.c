#include<stdio.h>

int sum(int x, int i, int n){
	if(x == 0){
		return 0;
	}
	else{
		return i+sum(x-1,i+n-x,n);
	}
}

int main(){
	int n;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	int s = sum(n,1,n+1);
	printf("The sum of first %d even numbers is %d\n",n,s);
	return 0;
}
