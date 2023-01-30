#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	printf("We are in test2\n");
	printf("Pid of test2 = %u\n", getpid());
	return 0;
}
