#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	pid_t q;
	q=fork();
	if(q<0)
	printf("Error");
	else if(q==0)//child
	{
		printf("Child process\n");
		printf("Child having pid %d \n",getpid());
		printf("Parent pid is %d \n",getppid());
	}
	else
	{
		printf("Parent pid is %d \n",getppid());
		printf("Child pid is %d\n",q);
	}
return 0;
}
