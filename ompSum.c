#include<stdio.h>
#include<omp.h>

int main(){

	int i,sum = 0;
	#pragma omp parallel for reduction(+: sum)
	for(i = 1; i<=10; i++){
		printf("i = %d, sum = %d, thread = %d\n",i, sum, omp_get_thread_num());
		sum += i;
	}
	printf("Sum = %d\n",sum);
	return 0;
}
