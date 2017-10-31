/***********************************************
 * Program to get the file status using stat()
 *
 * Author : Lal Bosco Lawrence
 * Date   : 31-oct-2017 
 * Ref    : man stat
 ************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>

/* stat() : Get the status of a file
 * Takes the file name/path as arg
 */
int main(int argc, char **argv)
{
	struct stat statbuf;

	/* Validation of input */
	if (argc != 2) {
		printf("Invalid command ...\n");
		printf("usage: <%s> <file_name>\n", argv[0]);
		exit(-1);
	}

	if (lstat(argv[1], &statbuf)) {
		printf("stat is failed\n");
		exit(-1);
	} 

	printf("\nFile Name                 : %s\n",argv[1]);
	printf("File Type                 : ");
	/* File Type */
	if (S_ISREG(statbuf.st_mode))
		printf("Regular file\n");
	if (S_ISDIR(statbuf.st_mode))
		printf("Airectory file\n");
	if (S_ISCHR(statbuf.st_mode))
		printf("Character device file\n");
	if (S_ISBLK(statbuf.st_mode))
		printf("Block device file\n");
	if (S_ISFIFO(statbuf.st_mode))
		printf("FIFO/Pipe file\n");
	if (S_ISLNK(statbuf.st_mode))
		printf("Symbolic link file\n");
	if (S_ISSOCK(statbuf.st_mode))
		printf("Socket file\n");

	printf("I-node number is          : %ld\n",(long) statbuf.st_ino);

	/* Get the User and Group name */
	struct passwd *user  = getpwuid(statbuf.st_uid);
	struct group  *group = getgrgid(statbuf.st_gid);
	printf("User Name                 : %s\n",user->pw_name);
	printf("Group Name                : %s\n",group->gr_name);

	printf("Ownership                 : UID : %d GID : %d\n",
	statbuf.st_uid, statbuf.st_gid);

	printf("Link count                : %d\n",(int) statbuf.st_nlink);

	printf("Block size                : %ld bytes\n",
	(long) statbuf.st_blksize);
	printf("File size                 : %lld bytes\n",
	(long long) statbuf.st_size);
	printf("Blocks allocated          : %lld\n",
	(long long) statbuf.st_blocks);

	printf("File mode                 : %o\n",statbuf.st_mode);
	printf("File Permissions          : %o\n\n", statbuf.st_mode & 0777);

	/* ctime()'s return value includes a \n, which is silly but true */
	/* see time.c for more example time stuff */
	printf("%s was last modified %s", argv[1], ctime(&statbuf.st_mtime));
	printf("%s was last accessed %s", argv[1], ctime(&statbuf.st_atime));
	printf("%s's ctime is %s\n", argv[1], ctime(&statbuf.st_ctime));

	return 0;
}

