#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[]){
	//printf("We are in myecho\n");
	write(1, argv[1], strlen(argv[1]));
	return 0;
}
