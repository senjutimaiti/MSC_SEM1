/*Date: 22/09/2022*/

/*Write a C program that will echo the argumnts sent o it through the 
commnd line. Name the program "myecho"*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 


int main(int argc, char* argv[]){
  
	int i = 0;
  
	printf("The Command line arguments are :-\n");
	
	while(argv[i] != NULL ) {
		printf("argv[%d] : %s\n", i, argv[i]);
		i = i + 1;
	}
  
	/* The difference between a peaceful and a restless person is their 
	ability to pick and choose their thoughts*/
	return 0;
}

/*Output*/

/*

$./5_myecho hello world

The Command line arguments are :-
argv[0] : ./5_myecho
argv[1] : hello
argv[2] : world

*/
