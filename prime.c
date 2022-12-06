#include<stdio.h>
#include<math.h>

int checkprime(int n,int i){
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

int main(){
	int l,h;
	printf("Enter the lower and upper limit respectively: ");
	scanf("%d", &l);
	scanf("%d", &h);
	if(l<=h){
		int i;
		printf("The prime numbers are: ");
		for(i = l; i<=h; i++){
			if(checkprime(i,i/2)){
				printf("%d ",i);
			}
		}
		printf("\n");
	}
	return 0;
}
