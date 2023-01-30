#include <stdio.h>
#include <omp.h>

main() {

	int i, sum = 0;
	
	#pragma omp parallel for reduction (+:sum)
	for(i = 1 ; i <= 5; i++)
		sum += i*(i+1);
	
	printf("\n sum = %d", sum);

}
