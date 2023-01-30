#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
	int fd;
	fd = open("test3.txt",O_RDWR|O_EXCL,S_IREAD|S_IWRITE);
	if(fd != -1){
		char message[20];
		read(fd, message, sizeof(message));
		printf("\"%s\" was written to test2.txt file\n", message);
		close(fd);
	}
	else{
		int fd1 = creat("test3.txt",O_CREAT);
	}
	
	return 0;
}
