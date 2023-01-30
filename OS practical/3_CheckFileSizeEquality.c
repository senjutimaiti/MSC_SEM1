/*Date: 15/09/2022*/

/*WAP in C using system calls to check whether sizes of files cretaed in 
Assignment_1 and Assignment_2 are same or not.*/

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> //for close()
#include <string.h> //for fgets()

/*This function gets string input from user. I have to rewrite gets() 
 * since it has been deprecated in C11. Instead of gets() we are asked 
 * to use fgets(). Now, fgets() also takes in the newline character '\n' at the end.
 * So it needs to be changed to null character '\0'. So that it can be 
 * treated as string. That is what this function does.*/
 
void gets(char * string, int n)
{
	fgets(string, n, stdin);

	while (*string != '\0'){
    
		if (*string == '\n'){
			*string = '\0';
			break;
		}
    
    string++;
	}
}

int main(){
	
	char filename1[21];
	printf("Enter the First file name [max. 20 chracters]: ");
	gets(filename1, 21);
	
	char filename2[21];
	printf("Enter the Second file name [max. 20 chracters]: ");
	gets(filename2, 21);
	
	int fileDescriptor1 = open(filename1, O_RDONLY, S_IRUSR);
	int fileDescriptor2 = open(filename2, O_RDONLY, S_IRUSR);
	
	char buffer[100];
	
	lseek(fileDescriptor1, 0L, 0);
	lseek(fileDescriptor2, 0L, 0);
	
	int fileSize_1 = read(fileDescriptor1, buffer, sizeof(buffer));
	printf("\nThe contents of First file: \n%s", buffer);
	
	int fileSize_2 = read(fileDescriptor2, buffer, sizeof(buffer));
	printf("\n\nThe contents of Second file: \n%s", buffer);	
	
	if(fileSize_1 == fileSize_2) {
		printf("\n\nEureka! The files have the same size! %d and %d\n", fileSize_1, fileSize_2);
	}
	else{
		printf("\n\nDamn it! The files don't have the same size! %d and %d\n", fileSize_1, fileSize_2);
	}
	
	close(fileDescriptor1);
	close(fileDescriptor2);
	
	/*Chaar assignment class ka, kaam mera roz ka*/
	return 0;

}

/*Output*/

/*
Enter the First file name [max. 20 chracters]: Text.file
Enter the Second file name [max. 20 chracters]: Text.file.copy

The contents of First file: 
The quick brown fox jumped over the lazy me.

The contents of Second file: 
The quick brown fox jumped over the lazy me.

Eureka! The files have the same size! 44 and 44


------------------
(program exited with code: 0)
Press return to continue
*/
