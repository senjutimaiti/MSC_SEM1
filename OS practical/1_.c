#include <stdio.h>
#include <omp.h>

int main(){
	int m, k;
	m = omp_get_num_procs();
	k = omp_get_max_threads();
	printf("Total number of processors = %d\n", m);
	printf("Maximum number of threads = %d\n", k);
	return 0;
}
