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
	
	int sum = 0;
	int i, sz;
	
	printf("%s", "\nSeries: 1! + 2! + 3! + ...\n");
	printf("%s", "\nEnter the length of series: ");
	scanf("%d", &sz);
	
	printf("\n");
	
	#pragma omp parallel for reduction (+:sum)
	for(i = 1 ; i <= sz; i++) {
	
		sum += fact(i);
		
		printf("Iteration no. = %d, Sum = %d. Thread[%d]\n\n", i, sum, omp_get_thread_num());
	}
	
	printf("Sum = %d\n\n", sum);

	return 0;

}
