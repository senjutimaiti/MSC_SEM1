#include <stdio.h>
#include <omp.h>

int main() {
	int A[3][3] = { {1, 1, 3}, {2, 2, 1}, {2, 1, 3} };

	int det = 0;
	int i;
	
	#pragma omp parallel for reduction (+:det)
	for(i = 0; i < 3; ++i)
		det += A[0][i] * ( A[1][(i+1)%3] * A[2][(i+2)%3] - A[2][(i+1)%3] * A[1][(i+2)%3] );
	
	
	printf("\nDeterminant: %d\n", det);
	
	return 0;
}
