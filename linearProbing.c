#include<stdio.h>
#define N 10

void probing(int a[], int n, int s){
	s=(s+1)%N;
	while(a[s] != -99){
		s=(s+1)%N;
	}
	a[s] = n;
}

void hashing(int k[], int a[]){
	int i;
	for(i=0; i<N; i++){
		if(a[k[i]%N] == -99){
			a[k[i]%N] = k[i];
		}
		else{
			probing(a, k[i], (k[i]%N));
		}
	}
}

int main(){
	int keys[]={28,93,26,27,13,38,04,45,77,63};
	int a[N], i;
	
	for(i=0; i<N; i++)
		a[i]=-99;
	
	hashing(keys, a);
	
	for(i=0; i<N; i++)
		printf("%d ",a[i]);
	
	printf("\n");
		
	return 0;
}
