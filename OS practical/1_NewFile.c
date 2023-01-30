/*Date: 15/09/2022*/

/*WAP in C using system calls to create a new text file by accepting 
the texts from the standard input.*/

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
	printf("Enter the name of new file [max. 20 chracters]: ");
	gets(filename, 21);
	
	int fileDescriptor = open(filename, O_CREAT|O_RDWR, S_IRWXU);
	
	char text[101];
	printf("\nWrite the text and enter [max. 100 chracters]: \n");
	gets(text,101);

	write(fileDescriptor, text, strlen(text));
	
	close(fileDescriptor);
	
	printf("\n\nTo see the contents of New File run Assignment_4.c\n");
	
	/*Chote bacche jaan ke pyare aankh dikhana re, dubi dubi dub dub*/
	return 0;

}

/*Output*/

/*

Enter the name of new file [max. 20 chracters]: Text.file

Write the text and enter [max. 100 chracters]: 
The quick brown fox jumped over the lazy me.


To see the contents of New File run Assignment_4.c


------------------
(program exited with code: 0)
Press return to continue

*/
