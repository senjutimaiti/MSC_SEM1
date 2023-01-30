#include<stdio.h>
#include<omp.h>

int main(){

	omp_set_dynamic(0);
	int A[10] = {0,1,2,3,4,5,6,7,8,9},i,m;

	m = omp_get_num_procs();
	omp_set_num_threads(m);
	
	#pragma omp parallel for shared(A) private(i)
	for(i=0; i<10; i++)
	printf("A[%d] = %d from thread %d of %d\n",i, A[i], omp_get_thread_num(), omp_get_num_threads());

	return 0;
}
