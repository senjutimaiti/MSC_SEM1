#include<stdio.h>

void Merge(int a[], int l, int m, int h){
	int i=l, j=m+1, k=0;
	int c[h-l+1];
	while(i<m+1 && j<h+1){
		if(a[i]<=a[j]){
			c[k++] = a[i++];
		}
		else{
			c[k++] = a[j++];
		}
	}
	
	while(i<m+1){
		c[k++]=a[i++];
	}
	
	while(j<h+1){
		c[k++]=a[j++];
	}
	
	k=0;
	i=l;
	while(i<h+1){
		a[i++]=c[k++];
	}
}

void MergeSort(int a[], int l, int h){
	int m;
	if(l<h){
		m=(l+h)/2;
		MergeSort(a,l,m);
		MergeSort(a,m+1,h);
		Merge(a,l,m,h);
	}
}

int main(){
	int a[]={4,7,3,5,1,6,2};
	MergeSort(a,0,6);
	int i;
	for(i = 0; i<7; i++){
		printf("%d ",a[i]);
	}
	return 0;
}
