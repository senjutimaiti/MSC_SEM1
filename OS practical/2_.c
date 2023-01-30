#include <stdio.h>
#include <omp.h>

int main(){
	
	int m, k;

	m = omp_get_num_procs();
	k = omp_get_max_threads();
	
	printf("\n");
	printf("Total number of processors = %d\n", m);
	printf("Maximum number of threads = %d\n", k);
	
	omp_set_dynamic(0);
	omp_set_num_threads(100);
	
	#pragma omp parallel
	printf("\nHello from %d of %d", omp_get_thread_num(), omp_get_num_threads() );
	     
	return 0;
	
}
