#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> /* Manipulate file descriptor */ 
#include <unistd.h> /* symbolic constant and types */
#include <stdbool.h> /* boolean variables */
#include <ctype.h> /* Check for digits in string */

int main(int argc, char *argv[])
{
	// Read 1024 characters
	const int SIZE = 1024;

	// Activate shift argument
	bool shift = false;
	
	// Activate reverse argument
	bool reverse = false;
	
	// Activate output numbers
	bool num_line = false;
	
	// Create file buffer
	char buf[SIZE];
	char c;
	
	// shifts
	int n=0;
	
	// Collects an array of value arguments
	// accepts up to 50 numbers
	char val_collect[50]={0};
	
	// file descriptor
	int fd;
	
// No Arg
	if (argc==1) {
	printf("Command not found\n"); 
	printf("Use -s num to shift num spaces\n");
	printf("Use -r with -s num to reverse shifts\n");
	printf("Use -n to number output lines\n");
	exit(0); }
	
// Arg Parse
	int args=argc;
	// Checks when '-' is used
	int argument_valid=0;
	// Compares to expected arguments
	int validator = 0;
	while (args--)	
	{
		if(argv[args][0] == '-')
		{
			int command_len = (int) strlen (argv[args]);
			
			// Argument expected
			argument_valid++;
			/* find args */
			// Validator confirms expected args
			while (command_len--)
			{
				if(argv[args][command_len]=='n'){ 
				num_line = true;
				validator++; }
				if(argv[args][command_len]=='s'){ 
				shift = true;
				
				// Takes in an integer
				// If integer is not taken, error is displayed
				int index=0;
				// Find the numerical values up to 50 digits
				if (!isdigit(argv[args][command_len+2]))
				{
				    printf("Error no shift numerical value followed by space\n"); 
				    printf("Use -s num to shift num spaces\n");
				    printf("Use -r with -s num to reverse shifts\n");
				    printf("Use -n to number output lines\n");
				    exit(0);
				}
				// Take numerical value as character array
				while (isdigit(argv[args][command_len+2+index]))
				{
				    val_collect[index]=argv[args][command_len+2+index];
				    index++;
				}
				validator++; }
				if(argv[args][command_len]=='r'){ 
				reverse = true;
				validator++; }
			}
			
			// Invalid Args
			// Case '-' without argument or more than 3 args
			// Also check for reverse with no shift
			if ((reverse==true && shift==false) ||
			    argument_valid != validator || argument_valid > 3)
			{
				printf("Unexpected Command\n"); 
				printf("Use -s num to shift num spaces\n");
				printf("Use -r with -s num to reverse shifts\n");
				printf("Use -n to number output lines\n");
				exit(0);
			}
		}
	}
	
// Conversion of args into int values for shifting
	int index=0;
	while(val_collect[index]!=0)
	{
	    n*=10;
	    n+=(int)(val_collect[index]-'0');
	    index++;
	}
	n=n%26;
// open file
	fd = open( argv[argc-1], O_RDONLY );
	if ( fd == -1 )
	{
        	perror( argv[argc-1] ); 
        	exit(1);
	}
	
	int numRead=0;
	index=0;
	bool newl=true;
	int count=1;
// read and parse
	while ((numRead=read(fd,buf,SIZE))>0)
	{
		for (index=0;index<numRead;index++)
		{
			
			c=buf[index];
			
			if (num_line && newl==true)
			{
				printf("%d",count);
				printf(" ");
				newl=false;
				count++;
			}
			if (c=='\n')
			{
				newl=true;
				printf("\n");
				continue;
			}
			if (reverse && shift)
			{
				// If c passes "a"
				if (c>=97 && c>90)
				{
					// Iterate from z
					int iter=0;
					while (iter < n)
					{
						c = c - 1;
						if (c == 96)
						{
							c=122;
						}
						iter++;
					}
				}
				else
				{
					int iter=0;
					while (iter < n)
					{
						c = c - 1;
						if (c == 64)
						{
							c=90;
						}
						iter++;
					}
				}
				
				
			}
			// Shifting case
			else
			{
				// case lower 
				if (c >= 97 && c > 90)
				{
					int iter = 0;
					while (iter < n)
					{
						c = c + 1;
						if (c==123)
						{
							c=97;
						}
						iter++;
					}
				}
				// case upper
				else
				{
					int iter = 0;
					while (iter < n)
					{
						c = c + 1;
						if (c==91)
						{
							c=65;
						}
						iter++;
					}
				}
			}
			printf("%c",c);
			
		}
	}
// Close
	close(fd);
	char exit;
	//printf("Enter a key to exit: ");
	scanf("%c", &exit);
	return 0;
}
