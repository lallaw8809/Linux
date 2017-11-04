/***********************************************
 * Program to dup() : Create a duplicate fd
 *
 * Author : Lal Bosco Lawrence
 * Date   : 04-Nov-2017
 ************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* The dup() creates a copy of a file descriptor.
 * It uses the lowest-numbered unused file descriptor for the new descriptor.
 * If the copy is successfully created, then the original (fd) and copy file
   descriptors (copy_fdf) may be used interchangeably.
 * They both refer to the same open file description and thus share file offset and
   file status flags.
*/

#define BUZ_SIZE   1023
#define PERMISSION 0777

int main(int argc, char *argv[])
{
	int fd,copy_fd;
	char buf_1[BUZ_SIZE] = "dup : This is line one\n";
	char buf_2[BUZ_SIZE] = "dup : This is line two\n";
	char buf[BUZ_SIZE];

	/* Validation of input */
	if(argc != 2){
		printf("Invalid command...\n");
		printf("Usage : <%s> <file_name>\n",argv[0]);
		exit(-1);
	}

	printf("dup : Write and read a data into a file using duplicate fd...\n");
	sleep(2);

	/* Open or create the file */
	fd      = open(argv[1],O_RDWR|O_CREAT|O_APPEND,PERMISSION);
	if(fd<0){
		printf("Unable to [%s] open or create is failed\n",argv[1]);
		exit(-1);
	}

	/* Create a duplicate file descriptor */
	copy_fd = dup(fd);

	/*  Write a data into a file using original fd */
	write(fd,buf_1,BUZ_SIZE);

	/*  Write a data into a file using original fd */
	write(copy_fd,buf_2,BUZ_SIZE);

	/* Read the file */
	strcpy((char*)buf,(char*)"cat ");
	strcat((char*)buf,(char*)argv[1]);
	printf("Reading the file...\n");
	system(buf);

	/* Close the file */
	close(fd);
	close(copy_fd);

	return 0;
}

