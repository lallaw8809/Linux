/***********************************************
 * Program to dup2() : Create a duplicate fd and
 *  re-ditect the stdout into a file
 *
 * Author : Lal Bosco Lawrence
 * Date   : 04-Nov-2017
 ************************************************/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUZ_SIZE   1023
#define PERMISSION 0777

#define METHOD_1

/* The dup2() system call is similar to dup() but the basic difference between them is
   that instead of using the lowest-numbered unused file descriptor, it uses the 
   descriptor number specified by the user.

   Method 1 :
	New fd is stdout
	All the printf statements will be written in the file
   Method 2 :
	Get the duplicate fd and write a data into a file using new_fd
*/
int main(int argc, char *argv[])
{
	int fd,new_fd;
	char buf_1[BUZ_SIZE] = "dup2 : This is line one\n";
	char buf_2[BUZ_SIZE] = "dup2 : This is line two\n";
	char buf[BUZ_SIZE];

	/* Validation of input */
	if(argc != 2){
		printf("Invalid command...\n");
		printf("Usage : <%s> <file_name>\n",argv[0]);
		exit(-1);
	}

	/* Open the file */
	fd = open(argv[1], O_RDWR|O_CREAT, PERMISSION);
	if(fd<0){
		printf("Unable to [%s] open or create is failed\n",argv[1]);
		exit(-1);
	}

#ifdef METHOD_1
	printf("dup2 : Write a data into a file using STDOUT fd...\n");
	printf("To read a file, please usse the following command\n");
	printf("cat %s\n",argv[1]);
	sleep(2);

	/* here the newfd is the file descriptor of stdout (i.e. 1) */
	dup2(fd,1); //(old_fd,new_fd)
	
	/* All the printf statements will be written in the file */
	printf("dup2 : I am writing into a file from dup2()...\n");

#else
	printf("dup2 : Write and read a data into a file using duplicate fd...\n");
	sleep(2);

	/* Get the new_fd */
	new_fd = dup2(fd,new_fd); //(old_fd,new_fd)

	/*  Write a data into a file using original fd */
	write(new_fd,buf_1,strlen(buf_1)+1);

	/*  Write a data into a file using original fd */
	write(new_fd,buf_2,strlen(buf_2)+1);

	/* Read the file */
	strcpy((char*)buf,(char*)"cat ");
	strcat((char*)buf,(char*)argv[1]);
	printf("Reading the file...\n");
	system(buf);

#endif
	/* Close the fd */
	close(fd);
	close(new_fd);

	return 0;
}

