/***********************************
 * Program to print the file type
 * Author : Lal Bosco Lawrence   
 * Date   : 30-oct-2017 
 **********************************/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define METHOD_1

int main(int argc, char *argv[])
{
	struct stat statbuf;
	
	/* Validation  of input */
	if(argc != 2){
		printf("Invalid command...\n");
		printf("Usage : <./file_type> <file/folder_name>\n");
		exit(-1);
	}

	/* Get the status of the file */
	if (lstat(argv[1], &statbuf)){
		printf("Unable to get the file status\n");
		exit(-1);
	}
	
	/* validation of file types using differene method */
#ifdef METHOD_1
	printf("File type:                ");
	if (S_ISREG(statbuf.st_mode))
		printf("%s is a regular file\n", argv[1]);
	if (S_ISDIR(statbuf.st_mode))
		printf("%s is a directory\n", argv[1]);
	if (S_ISLNK(statbuf.st_mode))
		printf("%s is a symlink\n", argv[1]);
	if (S_ISCHR(statbuf.st_mode))
		printf("%s is a character driver file\n", argv[1]);
	if (S_ISBLK(statbuf.st_mode))
		printf("%s is a black driver file\n", argv[1]);
	if (S_ISFIFO(statbuf.st_mode))
		printf("%s is a FIFO/Pipe file\n", argv[1]);
	if (S_ISSOCK(statbuf.st_mode))
		printf("%s is a Socket file\n", argv[1]);

#else

	printf("File type:                ");
	switch (statbuf.st_mode & S_IFMT) 
	{
		case S_IFBLK:  printf("block device\n");            break;
		case S_IFCHR:  printf("character device\n");        break;
		case S_IFDIR:  printf("directory\n");               break;
		case S_IFIFO:  printf("FIFO/pipe\n");               break;
		case S_IFLNK:  printf("symlink\n");                 break;
		case S_IFREG:  printf("regular file\n");            break;
		case S_IFSOCK: printf("socket\n");                  break;
		default:       printf("unknown?\n");                break;
	}
#endif

}



















