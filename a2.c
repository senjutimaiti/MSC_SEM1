#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
	int fd1,fd2;
	fd1 = open("test1.txt",O_RDWR|O_EXCL,S_IREAD|S_IWRITE);
	if(fd1 != -1){
		char message[20];
		read(fd1, message, 20);
		fd2 = open("test2.txt",O_RDWR|O_CREAT|O_EXCL,S_IREAD|S_IWRITE);
		if(fd2 != -1){
			write(fd2, message, sizeof(message));
		}
		else{
			printf("Cannot be copied");
		}
		close(fd2);
	}
	else{
		printf("File already exists\n");
	}
	close(fd1);
	return 0;
}
