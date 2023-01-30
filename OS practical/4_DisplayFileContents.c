/*Date: 15/09/2022*/

/*WAP in C using system calls to display the contents of text file. If 
the text file does not exist then creat it with 0 length.*/

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
	
	char filename[21];
	printf("Enter the name of file to be opened [max. 20 chracters]: ");
	gets(filename, 21);
	
	int fileDescriptor = open(filename, O_CREAT | O_RDONLY, S_IRUSR);
	
	char buffer[100];
	lseek(fileDescriptor, 0L, 0);
	read(fileDescriptor, buffer, sizeof(buffer) );
	printf("\nThe Content:\n\n%s", buffer);
	
	close(fileDescriptor);
	
	/*Aata majhi satakli*/
	return 0;

}

/*Output*/

/*

Enter the name of file to be opened [max. 20 chracters]: Text.file

The Content:

The quick brown fox jumped over the lazy me.

------------------
(program exited with code: 0)
Press return to continue

*/
