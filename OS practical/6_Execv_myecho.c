/*Date: 22/09/2022*/

/*Write a C program to create a child process and make it execute the 
"myecho" program created in previous assignment.*/
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int status;
    
    printf("Hey there! I am parent process\n");
    
    int cp_id = fork();
    
    //Child process executes the if block
    if(cp_id == 0){
		
		
		printf("\nHey there! I am child process\n");
		printf("Executing ./5_myecho\n\n");
	
		char *args[]={"5_myecho","Hello","World",NULL};
		execv("5_myecho",args);
		
	}
	
	//Parent proces executes the else block.
	else{
		//Wait until child process completes executing the program.
		wait(&status);
	}
    
    printf("\nI am back! The parent process.\n");
	
	/*R.I.P*/
	return 0;
}

/*Output*/

/*
Hey there! I am parent process

Hey there! I am child process
Executing ./5_myecho

The Command line arguments are :-
argv[0] : ./5_myecho
argv[1] : Hello
argv[2] : World

I am back! The parent process.


------------------
(program exited with code: 0)
Press return to continue
*/
