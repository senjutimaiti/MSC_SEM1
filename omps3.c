#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(){

	int i,n,c,j;
	float f;
	printf("Enter a number ");
	scanf("%d",&n);
	float sum = 1;
	for(i = 2; i<=n; i++){
		c = 2*i-1;
		f=1;
		#pragma omp parallel for reduction(*: f)
		for(j=2; j<=c; j++){
			printf("i = %d, product = %f, thread = %d\n",i, f, omp_get_thread_num());
			f *= j;
			printf("i = %d, product = %f, thread = %d\n",i, f, omp_get_thread_num());
		}
		printf("%f\n",f);
		printf("%3.5f\n",(i/f));
		sum += (i/f);
	}

	printf("Sum of the series with n = %d is %f\n",n,sum);
	return 0;
}
