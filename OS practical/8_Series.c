#include <stdio.h>
#include <omp.h>

int fact(int num){
	int res = 1;
	while(num > 0){
		res = res * num;
		num = num - 1;
	}
	return res;
}

int main() {
	
	double sum = 0;
	int i, sz;
	
	printf("%s", "\nSeries: 1/1! + 2/3! + 3/5! + ...\n");
	printf("%s", "\nEnter the length of series: ");
	scanf("%d", &sz);
	
	printf("\n");
	
	#pragma omp parallel for reduction (+:sum)
	for(i = 1 ; i <= sz; i++) {
		
		sum += (double)i/fact(i*2-1);
		
		printf("Iteration no. = %d, Sum = %f. Thread[%d]\n\n", i, sum, omp_get_thread_num());
	}
	
	printf("Sum = %f\n\n", sum);

	return 0;

}
