/***********************************
 * Program to open file and read using lseek and SEEK_END,SEEK_CUR and SEEK_SET
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
	int fd, num_of_bytes, index = 0;
	char buf;

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

	/* SEEK_END : fd will moved into end of the file
	 * Get the number of character in a file 
	 */
	num_of_bytes = lseek(fd,-1,SEEK_END);
	lseek(fd,0,SEEK_SET);//fd will point the starting position

	while(num_of_bytes--)
	{
		/* read the file */
		if( read(fd,&buf,sizeof(char))  < 0)
			error_message("Unable to read the file");
		printf("%c",buf);
		lseek(fd,0,SEEK_CUR);//Moving char by char
	}
		
	

	/* Close the file */
	close(fd);
}

/* print the error message */
void error_message(char *message)
{
	printf("%s\n",message);
	exit(-1);
}

