#include <stdio.h>
#include <omp.h>

int main(){
	
	int A[10] = {0,1,2,3,4,5,6,7,8,9};
	int i = 0;
	
	omp_set_dynamic(0);
	omp_set_num_threads(4);
	
	printf("\n");
	
	#pragma omp parallel for shared(A) private(i)
	for(i = 0; i < 10; i++)
		printf("\nA[%d] = %d from %d of %d", i, A[i], omp_get_thread_num(), omp_get_num_threads() );
	     
	
	return 0;
	
}
