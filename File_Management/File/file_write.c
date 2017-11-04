/********************************************
 * Program to open or create a file and write 
 * Author : Lal Bosco Lawrence   
 * Date   : 20-oct-2017 
 ********************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error_message(char *message);

void main(int argc, char *argv[])
{
	int fd;

	/* Validation of input */
	if(argc != 3)
	{
		printf("Invalid command\n");
		printf("Usage : <./file_write> <file_path> <MESSAGE>\n");
		printf("Example : <./file_write> <bin/file.txt> <'Hello All'>\n");
		exit(-1);	
	}

	/* Open the file, if exits or create a file */
	if ((fd = open(argv[1],O_CREAT | O_WRONLY , 0777)) < 0 )
		error_message("Unable to crweate a file\n");

	/* Write a data into a file */
	if(write(fd,argv[2], strlen(argv[2])+1 ) < 0)
		error_message("Unable to write the data into a file\n");

	/* Close the file */
	close(fd);

}

/* print the error message */
void error_message(char *message)
{
	printf("%s\n",message);
	exit(-1);
}
