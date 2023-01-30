#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

static char message[] = "Hello, World";

int main(){
	int fd;
	char buffer[80];
	fd = open("test.txt",O_RDWR|O_CREAT|O_EXCL,S_IREAD|S_IWRITE);
	if(fd != -1){
		printf("test.txt opened for read/write access\n");
		write(fd, message, sizeof(message));
		lseek(fd, 0L, 0);
		if(read(fd, buffer, sizeof(message)) == sizeof(message)){
			printf("\"%s\" was written to text.txt file\n", buffer);
		}
		else{
			printf("error reading the test.txt file\n");
		}
		close(fd);
	}
	else{
		printf("File already exists\n");
	}
	
	return 0;
}
