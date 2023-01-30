#include<stdio.h>
#include<omp.h>
int main()
{
int Q[20],f=0,r=-1,count=0;
int id,d,ins=0;
omp_set_dynamic(0);
#pragma omp parallel num_threads(2)
{
id=omp_get_thread_num();
if(id==0)
	while(1)
	{
	#pragma omp critical
		{
		if(count<20)
		  {
			r=(r+1)%20;
			ins++;
			Q[r]=ins;
			printf("Producer %d\n",ins);
			count++;
			
		  }
		else
			printf("Producer: no space\n");
		fgetc(stdin);
		}
	}
else
	while(1)
	{
	#pragma omp critical
	  {
		if(count!=0)
		{
			d=Q[f];
			f=(f+1)%20;
			printf("Consumer %d\n",d);
			count--;
			
		}
		else
			printf("Consumer: no items\n");
		fgetc(stdin);
	  }
	}
}
return 0;
}

