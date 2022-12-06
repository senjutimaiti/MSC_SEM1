#include<stdio.h>

int search(int a[],int l,int n){
	if(l<0){
		return 0;
	}
	else if(a[l] == n){
		return 1;
	}
	else{
		return search(a,l-1,n);
	}
}

int main(void){
	int a[] = {1,2,3,4,5};
	int result = search(a,4,3);
	if(result == 1){
		printf("Number Found\n");
	}
	else{
		printf("Number Not Found\n");
	}
	return 0;
}
