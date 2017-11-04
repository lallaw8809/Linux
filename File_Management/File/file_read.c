/***********************************
 * Program to open file and read 
 * Author : Lal Bosco Lawrence   
 * Date   : 20-oct-2017 
 **********************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void error_message(char *message);

void main(int argc, char *argv[])
{
	int fd;
	char buf[BUFSIZ];

	/* Validation of input */
	if(argc != 2)
	{
		printf("Invalid command\n");
		printf("Usage : <./file_read> <file_path>\n");
		exit(-1);	
	}

	/* Open the file */
	if( (fd = open(argv[1], O_RDONLY, 0777)) < 0)
		error_message("Unable to open the file.. Please check, if the file is exit");

	/* read the file */
	if( read(fd,buf,BUFSIZ ) < 0)
		error_message("Unable to read the file");

	/* this will terminate string with \0 
	 * To read the whole file, please refer lseek_end.c
	 */
	printf("%s\n",buf);

	/* Close the file */
	close(fd);
}

/* print the error message */
void error_message(char *message)
{
	printf("%s\n",message);
	exit(-1);
}

