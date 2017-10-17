/* Program to create file 
 * author : Lal Bosco Lawrence   
 */

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
	/* Validation of input */
	if(argc != 2){
		printf("Invalid command :\n");
		printf("Usage : <./create> <file_name> \n");
		exit(0);
	}

	/* File descriptor return values
		0 : Std input
		1 : Std output
		2 : Std error
	*/
	/* Create a file */
	int fd = creat(argv[1], 0777);

	/* Validation of file craetion */
	if(fd > 0)
		printf("File is created successfully...\n");
	else
		printf("File is not created...\n");

	/* Close the file*/
	close(fd);
}
