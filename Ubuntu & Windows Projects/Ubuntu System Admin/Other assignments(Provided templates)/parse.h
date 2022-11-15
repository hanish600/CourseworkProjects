/*
	The parse function accepts a string and breaks it up into
	an array of strings.
	For example:   The string ls -l -a is broken up into
	4 separate strings:
	ls
	-l
	-a
	/0
	The last string is the null terminator.  This array
	of strings can then be passed to execvp as it's second
	argument.
*/
#include "string.h"
#include "stdlib.h"

char** parse( char* str )
{
    char *token;
    char tokens[256];
    char** args = malloc( 256 );    
    int i = 0;
       
    strcpy( tokens, str );
    
    args[i] = strtok( tokens, " " );
    
    while( args[i] )
    {
    
        i++;
        args[i] = strtok(NULL, " ");
    } 
 
    return args;
}