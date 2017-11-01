/*********************************************
 * Program to create a different types of file
 *
 * Author : Lal Bosco Lawrence   
 * Date   : 01-Nov-2017 
 *********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define REGULAR_FILE	   1
#define DIRECTORY_FILE     2
#define FIFO_PIPE_FILE     3
#define CHAR_DEVICE_FILE   4
#define BLK_DEVICE_FILE    5
#define SOCKET_FILE        6
#define SYMBOLIC_LINK_FILE 7
#define HARD_LINK_FILE     8

void error_message(char *msg);
void validation_of_file(char *file_name);
void validation_of_input(int argc,char *exe_file);
void validation_link_file(int argc,char *exe_file);

int main(int argc, char *argv[])
{
	int choice;
	printf("Enter the types of file to create\n");
	printf("1. Regular file\n");
	printf("2. Directory file\n");
	printf("3. FIFO/pipe file\n");
	printf("4. Character device file\n");
	printf("5. Block device file\n");
	printf("6. Socket file\n");
	printf("7. Sybolic link file\n");
	printf("8. Hard link file\n");
	scanf("%d",&choice);

	switch(choice)
	{
		case REGULAR_FILE:
			/* Input validation */
			validation_of_input(argc,argv[0]);
			/* Validation of file exist */
			validation_of_file(argv[1]);
			/* create a regular file */
			if( creat(argv[1],O_CREAT) < 0)
				error_message("Unable to create a file");	
			break;

		case DIRECTORY_FILE :
			/* Input validation */
			validation_of_input(argc,argv[0]);
			/* Validation of file exist */
			validation_of_file(argv[1]);
			/* Creat a directory */
			if(mkdir(argv[1], 0700) < 0)
				error_message("Failed to create a directory");
			break;

		case FIFO_PIPE_FILE :
			/* Input validation */
			validation_of_input(argc,argv[0]);
			/* Validation of file exist */
			validation_of_file(argv[1]);
			/* Creat a fifo/pipe file */
			if(mkfifo(argv[1], 0700) < 0 )
				error_message("Unable to create a FIFO type file");
			break;

		case CHAR_DEVICE_FILE :
			/* Input validation */
			validation_of_input(argc,argv[0]);
			/* Validation of file exist */
			validation_of_file(argv[1]);
			/* create a character device file */
			if(mknod(argv[1], (S_IFCHR|0600),0) < 0){
				printf("Try with sudo...\n");
				error_message("Unable to create a char device type file");
			}
			break;

		case BLK_DEVICE_FILE :
			/* Input validation */
			validation_of_input(argc,argv[0]);
			/* Validation of file exist */
			validation_of_file(argv[1]);
			/* create a block device file */
			if(mknod(argv[1],(S_IFBLK|0600),0) < 0){
				printf("Try with sudo...\n");
				error_message("Unable to create a block device type file");
			}
			break;

		case SOCKET_FILE :
			/* Input validation */
			validation_of_input(argc,argv[0]);
			/* Validation of file exist */
			validation_of_file(argv[1]);
			/* create a socket file */
			if(mknod(argv[1], S_IFSOCK|0666,0) < 0)
				error_message("Unable to create a socket type of file");
			break;

		case SYMBOLIC_LINK_FILE :
			/* Input validation */
			validation_link_file(argc,argv[0]);
			/* Soft_Link the file */
			if( symlink(argv[1],argv[2]) < 0)
				error_message("Unable to soft link the file\n");
			break;

		case HARD_LINK_FILE :
			/* Input validation */
			validation_link_file(argc,argv[0]);
			/* Link the file */
			if( link((const char*)argv[1],(const char*)argv[2]) < 0 )
				error_message("Unable to hard link the file\n");
			break;
	
		default:
			printf("Invalid option\n");
			exit(-1);
	}

	printf("\n%s : Successfully created\n\n",argv[1]);
	return 0;
}

/* fuction to valdate the file exist */
void validation_of_file(char *file_name)
{
	struct stat st = {0};
	if (stat(file_name, &st) != -1){
		printf("File <%s> already exists\n",file_name);
		exit(-1);
	}
}

/* Function to validate the input for link */
void validation_link_file(int argc,char *exe_file)
{

	if(argc != 3){
		printf("Invalid command...\n");
		printf("Usage : <%s> <file_1> <file_2>\n",exe_file);
		exit(-1);
	}
}

/* Function to validate the input */
void validation_of_input(int argc,char *exe_file)
{
	if(argc != 2)
	{
		printf("Invalid command...\n");
		printf("Usage : <%s> <file_name>\n",exe_file);
		exit(-1);
	}
}

/* function to print the error message */
void error_message(char *msg)
{
	printf("%s\n",msg);
	exit(-1);
}
