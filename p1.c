#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
	int fd = open("test5.txt",O_RDWR|O_CREAT|O_EXCL,S_IREAD|S_IWRITE);
	if(fd != -1){
		char message[20];
		read(0, message, sizeof(message));
		write(fd, message, sizeof(message));
		close(fd);
	}
	else{
		printf("File already exists\n");
	}
	return 0;
}
