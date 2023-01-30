/*Date: 15/09/2022*/

/*WAP in C using system calls to make a copy of the text file created in 
Assignment_1.*/

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> //for close()
#include <string.h>

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
	printf("Enter the Original File name [max. 20 chracters]: ");
	gets(filename1, 21);
	
	char filename2[21];
	printf("Enter the New file name [max. 20 chracters]: ");
	gets(filename2, 21);
	
	int fileDescriptor1 = open(filename1, O_RDONLY, S_IRUSR);;
	int fileDescriptor2 = open(filename2, O_CREAT|O_RDWR, S_IRWXU);
	
	char buffer[100];
	lseek(fileDescriptor1, 0L, 0);
	
	read(fileDescriptor1, buffer, sizeof(buffer));
	printf("\nThe contents of Source File: \n%s", buffer);
	
	write(fileDescriptor2, buffer, strlen(buffer));
	
	close(fileDescriptor1);
	close(fileDescriptor2);
	
	printf("\n\nTo see the contents of Destination File run Assignment_4.c\n");
	
	/*Yahi Umar hai karle, Galti se Mistake*/
	return 0;

}

/*Output*/

/*
 
Enter the Original File name [max. 20 chracters]: Text.file
Enter the New file name [max. 20 chracters]: Text.file.copy

The contents of Source File: 
The quick brown fox jumped over the lazy me.

To see the contents of Destination File run Assignment_4.c


------------------
(program exited with code: 0)
Press return to continue

*/
