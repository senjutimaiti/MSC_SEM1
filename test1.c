#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	printf("Pid of test1 = %u\n", getpid());
	char* args[]={"Hello", "World", NULL};
	execv("./test2",args);
	printf("Back to test1");
	return 0;
}
