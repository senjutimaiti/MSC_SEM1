#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
	int fd1,fd2;
	fd1 = open("test1.txt",O_RDWR|O_EXCL,S_IREAD|S_IWRITE);
	fd2 = open("test2.txt",O_RDWR|O_EXCL,S_IREAD|S_IWRITE);
	if(fd1 != -1 && fd2 != -1){
		char message1[40];
		char message2[40];
		int len1 = read(fd1, message1, sizeof(message1));
		int len2 = read(fd2, message2, sizeof(message2));
		//printf("%d %d", len1,len2);
		if(len1 == len2){
			printf("Same size\n");
		}
		else{
			printf("Different size\n");
		}
	}
	else{
		printf("Can't open file\n");
	}
	close(fd1);
	close(fd2);
	return 0;
}
