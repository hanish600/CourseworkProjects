#include <unistd.h>
#include <wait.h>  
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <signal.h>
#include "parse.h"

#define MAX 256

struct termios stock;

void ctrlc(int);

int main(){
	
	if( tcgetattr( 0, &stock ) == -1 ){
		perror("GAH!");
		exit(1);
	}
	
	signal(SIGINT, ctrlc );
	while(1){
		int pid, exitstatus;
		char input[MAX];
		printf("$"); 
		fgets(input, MAX, stdin);
		int end=strlen(input)-1;
		if(input[end]=='\n')input[end]='\0';
		char **args=parse(input);                         
		
		if(args[0]){
			if(strcmp(args[0],"exit")==0)exit(0);  
			pid = fork();                                  
			switch( pid )
			{
				case -1:
					perror( "fork failed" );
					exit(1);
				case 0:
					execvp( args[0], args );
					perror( "execvp failed" );
					exit(1);
				default:
					while( wait( &exitstatus ) != pid );
			}  
			
		}
	}
	
	if( tcsetattr( 0, TCSANOW, &stock ) == -1 ){
		perror("GAH!");
		exit(1);
	}
	return 0;
}

void ctrlc(int num){
	int lame;	
}
