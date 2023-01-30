#include<stdio.h>
#include<omp.h>
#include<string.h>

int main(){

	int n=3, a[3][3]={{1, 2, 3}, {3, 1, 2}, {2, 3, 1}}, b[3][3]={{4, 5, 6}, {6, 4, 5}, {5, 6, 4}};
	int k,i,j,sum;
	int c[3][3]={{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	
	for(k=0; k<n; k++){
		for(i=0; i<n; i++){
			sum = 0;
			#pragma omp parallel for reduction(+: sum)
			for(j=0; j<n; j++){
				sum = sum+a[k][j]*b[j][i];
				//printf("i = %d, sum = %d, thread = %d\n",j, sum, omp_get_thread_num());
			}
			c[k][i] = sum;
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
