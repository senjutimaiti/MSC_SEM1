/*Date: 22/09/2022*/

/*Write a C program to create a child process tht will create a text 
file by accepting characters from the keyboard. The parent process 
should then create another process that will display the text file 
created by the first child.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


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


int main()
{
	int status;
    
    printf("-->PARENT PROCESS WITH ID = %d BEGINS...\n\n",getpid());
    
    int cp_id;
    cp_id = fork();
    
    //First Child process executes this if block
    if(cp_id == 0){
		
		printf("->FIRST CHILD PROCESS WITH ID = %d BEGINS...\n\n", getpid());
		
		char filename[21];
		printf("Enter the name of new file [max. 20 chracters]: ");
		gets(filename, 21);
	
		int fileDescriptor = open(filename, O_CREAT|O_RDWR, S_IRWXU);
	
		char text[101];
		printf("\nWrite the text and enter [max. 100 chracters]:\n");
		gets(text,101);

		write(fileDescriptor, text, strlen(text));
	
		close(fileDescriptor);
	
		printf("\n<-FIRST CHILD PROCESS WITH ID = %d, ENDS.\n\n", getpid());
	
		return 0;
		
	}
	
	//Parent proces executes the else block while first child process is executing.
	else{
		//Wait until first child process completes executing the program.
		wait(&status);
	}
	
	//fork for second child process
	cp_id = fork();
	
	//Second Child process executes this if block
	if(cp_id == 0){
		
		printf("->SECOND CHILD PROCESS WITH ID = %d BEGINS...\n\n", getpid());
		
		char filename[21];
		printf("Enter the name of file to be opened [max. 20 chracters]: ");
		gets(filename, 21);
	
		int fileDescriptor = open(filename, O_CREAT | O_RDONLY, S_IRUSR);
	
		char buffer[100];
		lseek(fileDescriptor, 0L, 0);
		read(fileDescriptor, buffer, sizeof(buffer) );
		printf("\nThe Content:\n%s", buffer);
	
		close(fileDescriptor);
	
		printf("\n\n<-SECOND CHILD PROCESS WITH ID = %d ENDS", getpid());
	
		return 0;
	}
	
	//Parent proces executes the else block while second child process is executing.
	else{
		//Wait until second child process completes executing the program.
		wait(&status);
	}
    
    printf("\n\n<--PARENT PROCESS WITH ID = %d ENDS.", getpid());
	
	/*Don't spit out your anger, don't swallow it. 
	Rinse it with mindfulness, with compassion, with love*/
	return 0;
}


/*Output*/

/*
-->PARENT PROCESS WITH ID = 4991 BEGINS...

->FIRST CHILD PROCESS WITH ID = 4992 BEGINS...

Enter the name of new file [max. 20 chracters]: Text.file

Write the text and enter [max. 100 chracters]:
Just some random text.

<-FIRST CHILD PROCESS WITH ID = 4992, ENDS.

->SECOND CHILD PROCESS WITH ID = 4994 BEGINS...

Enter the name of file to be opened [max. 20 chracters]: Text.file

The Content:
Just some random text.

<-SECOND CHILD PROCESS WITH ID = 4994 ENDS

<--PARENT PROCESS WITH ID = 4991 ENDS.

------------------
(program exited with code: 0)
Press return to continue

*/
