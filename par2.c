#include<stdio.h>
#include<omp.h>

int main(){

	omp_set_dynamic(0);
	int A[5] = {0,2,4,6,8};
	int B[5] = {1,3,5,7,9};
	int C[5];
	int i,m;

	m = omp_get_num_procs();
	omp_set_num_threads(m);
	
	#pragma omp parallel for shared(A) private(i)
	for(i=0; i<5; i++){
		C[i] = A[i] + B[i];
		printf("C[%d] = %d from thread %d of %d\n",i, C[i], omp_get_thread_num(), omp_get_num_threads());
	}

	return 0;
}
