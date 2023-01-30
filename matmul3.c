#include<stdio.h>
#include<omp.h>
#include<string.h>

int main(){
	omp_set_dynamic(0);

	int n=3, a[3][3]={{1, 2, 3}, {3, 1, 2}, {2, 3, 1}}, b[3][3]={{4, 5, 6}, {6, 4, 5}, {5, 6, 4}};
	int k,i,j,sum;
	int c[3][3]={{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	
	for(k=0; k<n; k++){
		#pragma omp parallel num_threads(3)
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				c[k][i] = c[k][i] + a[k][j]*b[j][i];
			}
		printf("k = %d, i = %d, thread = %d\n",k, i, omp_get_thread_num());
		}
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
