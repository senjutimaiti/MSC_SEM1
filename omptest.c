#include<stdio.h>
#include<omp.h>

int main(){

	omp_set_dynamic(0);

	int k,m;
	k = omp_get_max_threads();
	m = omp_get_num_procs();

	printf("Number of processor = %d\nNumber of max threads = %d\n",m,k);

	//omp_set_num_threads(6);
	//#pragma omp parallel
	#pragma omp parallel num_threads(1000)
	printf("This is %d of %d\n",omp_get_thread_num(), omp_get_num_threads());

	return 0;
}
