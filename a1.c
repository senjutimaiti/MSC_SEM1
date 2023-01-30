#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
	int fd;
	fd = open("test1.txt",O_RDWR|O_CREAT|O_EXCL,S_IREAD|S_IWRITE);
	if(fd != -1){
		char message[20];
		printf("Enter the message to be written\n");
		read(0, message, 20);
		write(fd, message, sizeof(message));
	}
	else{
		printf("File already exists\n");
	}
	close(fd);
	return 0;
}
