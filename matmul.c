#include<stdio.h>
#include<omp.h>
#include<string.h>

int main(){

	int n=3, a[3][3]={{1, 2, 3}, {3, 1, 2}, {2, 3, 1}}, b[3][3]={{4, 5, 6}, {6, 4, 5}, {5, 6, 4}};
	int x,y,z,i,j;
	int c[3][3]={{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	
	#pragma omp parallel sections
	{
		#pragma omp section
		{
			for(i=0; i<n; i++){
				for(j=0; j<n; j++){
					c[0][i] = c[0][i]+a[0][j]*b[j][i];
				}
			}
		}
		#pragma omp section
		{
			for(i=0; i<n; i++){
				for(j=0; j<n; j++){
					c[1][i] = c[1][i]+a[1][j]*b[j][i];
				}
			}
		}
		#pragma omp section
		{
			for(i=0; i<n; i++){
				for(j=0; j<n; j++){
					c[2][i] = c[2][i]+a[2][j]*b[j][i];
				}
			}
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
