#include <stdio.h>
#include <omp.h>

int main() {

	int i, sum = 0;
	int sz;
	
	printf("%s", "\nSeries: 1^2 + 2^2 + 3^2 + ...\n");
	printf("%s", "\nEnter the length of series: ");
	scanf("%d", &sz);
	
	printf("\n");
	
	#pragma omp parallel for reduction (+:sum)
	for(i = 1 ; i <= sz; i++) {
		sum += i*i;
		printf("Iteration no. = %d, Sum = %d. Thread[%d]\n\n", i, sum, omp_get_thread_num());
	}
	
	printf("Sum = %d\n\n", sum);

	return 0;

}
