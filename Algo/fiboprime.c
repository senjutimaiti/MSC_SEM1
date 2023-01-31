#include<stdio.h>
#include<math.h>

int checkprime(int n,int i){
	if(n == 1){
		return 0;
	}
	if(i == 1){
		return 1;
	}
	if(n%i == 0){
		return 0;
	}
	else{
		return checkprime(n,i-1);
	}
}

int fibo(int n){
	if(n < 3){
		return 1;
	} 
	else{
		return fibo(n-1)+fibo(n-2);
	}
}

int main(){
	int n,c=1,i=1,f;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	while(c<=n){
		f=fibo(i);
		if(checkprime(f,f/2)){
			printf("%d ",f);
			c++;
		}
		i++;
	}
	printf("\n");
	return 0;
}
