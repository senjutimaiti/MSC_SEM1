#include<stdio.h>

int binsearch(int a[],int l,int u,int n){
	int mid = (l+u)/2;
	if(u<l) {
		return 0;
	}
	else if(a[mid] == n) {
		return 1;
	}
	else if(a[mid] > n) {
		return binsearch(a,l,mid-1,n);
	}
	else {
		return binsearch(a,mid+1,u,n);
	}
}

int main(void){
	int a[] = {1,2,3,4,5};
	int result = binsearch(a,0,4,8);
	if(result == 1){
		printf("Number Found\n");
	}
	else{
		printf("Number Not Found\n");
	}
	return 0;
}
