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
void execute( char*[] );

int main(){
	//save terminal settings
	if( tcgetattr( 0, &stock ) == -1 ){
		perror("GAH!");
		exit(1);
	}
	//setup handler for ctrl c
	signal(SIGINT, ctrlc );
	
	while(1){
		char input[MAX];
		printf("$"); //print prompt
		fgets(input, MAX, stdin);
		int end=strlen(input)-1;
		if(input[end]=='\n')input[end]='\0';
		char **args=parse(input);
		if(strcmp(args[0],"exit")==0)exit(0);
		//printf("%s\n",args[0]);

		execute(args);
		//printf("%c\n",input[0]);
		//get input
		//parse input
		//if(input==exit)exit(0);
		//fork
		//if(im the parent)wait;
		//if(im the child){
		//	execvp 
		//}
		
	}
	
	//restore terminal settings
	if( tcsetattr( 0, TCSANOW, &stock ) == -1 ){
		perror("GAH!");
		exit(1);
	}
	return 0;
}

void ctrlc(int num){
	//signal handler for ctrl c
	printf("ctrl C\n");
	exit(0);
	//return;	
}

void execute( char* arglist[] )
/*
    use fork and execvp and wait to do it
*/
{
    int pid, exitstatus;                            // of child
    
	printf("%s\n",arglist[0]);//debug
	
    pid = fork();                                   // make new process
    
    switch( pid )
    {
        case -1:
            perror( "fork failed" );
            exit(1);
        case 0:
            execvp( arglist[0], arglist );          // do it
            perror( "execvp failed" );
            exit(1);
        default:
            while( wait( &exitstatus ) != pid );
            printf( "child exited with status %d, %d\n",
                exitstatus>>8, exitstatus & 0377 );
    }  
}
