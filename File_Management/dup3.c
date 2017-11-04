/***********************************************
 * Program to dup3()
 *
 * Author : Lal Bosco Lawrence
 * Date   : 31-oct-2017
 ************************************************/

#include <fcntl.h>
#include <unistd.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUZ_SIZE   1023
#define PERMISSION 0777

/* dup3() is the same as dup2(), except it takes a flag*/

int main(int argc, char *argv[])
{
	int fd,new_fd;
	char buf[BUZ_SIZE] = "dup3 : I am writing into a file\n";

	/* Validation of input */
	if(argc != 2){
		printf("Invalid command...\n");
		printf("Usage : <%s> <file_name>\n",argv[0]);
		exit(-1);
	}

	printf("dup3 : Write a data into a file using STDOUT and dup fd...\n");
	printf("To read a file, please usse the following command\n");
	printf("cat %s\n",argv[1]);
	sleep(2);

	/* Open the file */
	fd     = open(argv[1],O_RDWR|O_CREAT,PERMISSION);
	if(fd<0){
		printf("Unable to [%s] open or create is failed\n",argv[1]);
		exit(-1);
	}

	/* Duplicate fd using dup3() */
	new_fd = dup3(fd,1,O_CLOEXEC);  //(old,new)

	/* Write a data into a file */
	write(new_fd,buf,strlen(buf));

	/* Close the file */
	close(fd);
	close(new_fd);

	return 0;
}

