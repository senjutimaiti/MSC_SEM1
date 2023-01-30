#include<stdio.h>
#include<omp.h>

int main(){

	int i,n,sum = 0;
	printf("Enter a number ");
	scanf("%d",&n);
	#pragma omp parallel for reduction(+: sum)
	for(i = 1; i<=n; i++){
		printf("i = %d, sum = %d, thread = %d\n",i, sum, omp_get_thread_num());
		sum += i*i;
		printf("i = %d, sum = %d, thread = %d\n",i, sum, omp_get_thread_num());
	}

	printf("Sum of the series with n = %d is %d\n",n,sum);
	return 0;
}
