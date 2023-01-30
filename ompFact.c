#include<stdio.h>
#include<omp.h>

int main(){

	int i,n,fact = 1;
	printf("Enter a number ");
	scanf("%d",&n);
	#pragma omp parallel for reduction(*: fact)
	for(i = 2; i<=n; i++){
		printf("i = %d, product = %d, thread = %d\n",i, fact, omp_get_thread_num());
		fact *= i;
		printf("i = %d, product = %d, thread = %d\n",i, fact, omp_get_thread_num());
	}

	printf("Factorial of %d is %d\n",n,fact);
	return 0;
}
