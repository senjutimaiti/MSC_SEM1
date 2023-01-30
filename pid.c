#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	printf("Pid = %u\n", getpid());
	printf("Parent's pid = %u\n", getpid());
	return 0;
}
