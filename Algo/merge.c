#include<stdio.h>

int input(int a[]){
	int n1,i,j,l;
	printf("Enter the length of array ");
	scanf("%d",&n1);
	for(i=0; i<n1; i++){
		scanf("%d",&j);
		a[i]=j;
		l=i;
		while(l>0){
			if(a[l]<a[l-1]){
				a[l]=a[l-1];
				a[l-1]=j;
				l--;
			}
			else{
				break;
			}
		}
	}
	
	i=0;
	while(i<n1){
		printf("%d ",a[i++]);
	}
	printf("\n");
	
	return n1;
}

int merge(int a[], int b[], int n1, int n2){
	int i=0,j=0,k=0;
	int c[n1+n2];
	while(i<n1 && j<n2){
		if(a[i]<=b[j]){
			c[k++] = a[i++];
		}
		else{
			c[k++] = b[j++];
		}
	}
	
	while(i<n1){
		c[k++]=a[i++];
	}
	
	while(j<n2){
		c[k++]=b[j++];
	}
	
	k=0;
	while(k<(n1+n2)){
		printf("%d ",c[k++]);
	}
	printf("\n");
	
	return 0;
}

int main(){
	
	//int a[] = {1,3,5,7,9};
	//int b[] = {2,4,6,8};
	int a[10],b[10];
	
	int n1 = input(a);
	int n2 = input(b);
	
	merge(a,b,n1,n2);
	return 0;
}
