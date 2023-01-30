#include <stdio.h>
#include <omp.h>

int main() {

	int i, sum = 0;
	int sz, term = 2;
	
	printf("%s", "\nSeries: 2^2 + 4^2 + 6^2 + ...\n");
	printf("%s", "\nEnter the length of series: ");
	scanf("%d", &sz);
	
	printf("\n");
	
	#pragma omp parallel for reduction (+:sum)
	for(i = 1 ; i <= sz; i++) {
	
		sum += term*term;
		term += 2;
		
		printf("Iteration no. = %d, Sum = %d. Thread[%d]\n\n", i, sum, omp_get_thread_num());
	}
	
	printf("Sum = %d\n\n", sum);

	return 0;

}
