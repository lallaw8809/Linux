/***********************************
 * Program to open file and read using lseek and SEEK_SET
 * Author : Lal Bosco Lawrence   
 * Date   : 20-oct-2017 
 **********************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void error_message(char *message);

void main(int argc, char *argv[])
{
	int fd;
	char buf[BUFSIZ];

	/* Validation of input */
	if(argc != 2){
		printf("Invalid command\n");
		printf("Usage : <./file_read> <file_path>\n");
		exit(-1);	
	}

	/* Open the file */
	if( (fd = open(argv[1], O_RDONLY, 0777)) < 0)
		error_message("Unable to open the file.. Please check, if the file is exit");

        /* SEEK_SET : fd will always point the stating char in a file 
	   and moved based on the offset */
	lseek(fd,5,SEEK_SET);	
	lseek(fd,5,SEEK_SET);
	if( read(fd,buf,BUFSIZ)  < 0) /* read the file */
		error_message("Unable to read the file");
	printf("Print from the 5th caharcter in a file...\n	%s\n",buf);

	/* Close the file */
	close(fd);
}

/* print the error message */
void error_message(char *message)
{
	printf("%s\n",message);
	exit(-1);
}

