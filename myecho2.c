#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[]){
	printf("We are in myecho2\n");
	execv("./myecho",argv);
	return 0;
}
