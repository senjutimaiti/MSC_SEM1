#include<stdio.h>

int partition(int a[], int low, int high)
{
	int pivot,l,h,t;
	pivot=a[low];
	l=low;
	h=high;
	while(l<h)
	{
		while(a[l]<pivot)
		l++;
		while(a[h]>pivot)
		h--;
		if(l<h) //swapping
		{
			t=a[h];
			a[h]= a[l];
			a[l]=t;
		}
	}
	a[l]=a[h];
	a[h]=pivot;
	return h;
}

void quicksort(int a[], int low, int high)
{
	int p;
	if(low<high)
	{
		p=partition(a,low,high);
		quicksort(a, low, p-1);
		quicksort(a, p+1, high);
	}
}

void display(int a[], int n)
{
	int i;
	printf("\nThe sorted array!\n");
	for(i=0;i<n;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int a[] = {3,6,2,7,4,1,5};
	quicksort(a,0,6);
	display(a,7);
	return 0;
}

