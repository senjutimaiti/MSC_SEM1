#include<stdio.h>
#include<omp.h>

int main(){

	float i,k,n,fact, sum = 1;
	printf("Enter a number ");
	scanf("%d",&n);
	for(k = 2; k<=n; k++){
		fact = 1;
		#pragma omp parallel for reduction(*: fact)
		for(i = 2; i<=k; i++){
			printf("i = %f, product = %d, thread = %d\n",i, fact, omp_get_thread_num());
			fact *= i;
			printf("i = %d, product = %d, thread = %d\n",i, fact, omp_get_thread_num());
		}
		printf("Factorial of %d is %d\n",k,fact);
		sum += fact;
	}
	
	printf("Sum of factorials if n = %d is %d\n",n,sum);
	return 0;
}
