/***********************************************
 * Program to get the file status using fstat()
 *
 * Author : Lal Bosco Lawrence
 * Date   : 31-oct-2017 
 * Ref    : man fstat
 ************************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>

/* fstat() : Get the status of a file
 * Takes the file descriptor as arg
 */
int main(int argc, char *argv[])
{
	struct stat sb;

	/* Validation  of input */
	if (argc != 2) {
		printf("Invalid command...\n");
		printf("Usage: <%s> <pathname>\n", argv[0]);
		exit(-1);
	}

	/* open the file */
	int fd =open(argv[1],O_RDWR,0777);
	/* fstat() stats the file pointed to by path and fills in buf. */
	if (fstat(fd, &sb) == -1){
		printf("fstat is failed\n");
		exit(-1);
	}

	/* Get the User and Group name */
	struct passwd *user  = getpwuid(sb.st_uid);
	struct group  *group = getgrgid(sb.st_gid);

	printf("\nFile Name                : %s\n",argv[1]);
	printf("User Name                : %s\n",user->pw_name);
	printf("Group Name               : %s\n",group->gr_name);

	/* Print the file type */
	printf("File type                : ");
	switch (sb.st_mode & S_IFMT) {
		case S_IFBLK:  printf("Block device\n");            break;
		case S_IFCHR:  printf("Character device\n");        break;
		case S_IFDIR:  printf("Directory\n");               break;
		case S_IFIFO:  printf("FIFO/pipe\n");               break;
		case S_IFLNK:  printf("Symlink\n");                 break;
		case S_IFREG:  printf("Regular file\n");            break;
		case S_IFSOCK: printf("Socket\n");                  break;
		default:       printf("Unknown?\n");                break;
	}
	printf("I-node number            : %ld\n", (long) sb.st_ino);

	printf("Mode                     : %lo (octal)\n",
	(unsigned long) sb.st_mode&0777);

	printf("Link count               : %ld\n", (long) sb.st_nlink);
	printf("Ownership                : UID : %ld   GID : %ld\n",
	(long) sb.st_uid, (long) sb.st_gid);

	printf("Preferred I/O block size : %ld bytes\n",
	(long) sb.st_blksize);
	printf("File size                : %lld bytes\n",
	(long long) sb.st_size);
	printf("Blocks allocated         : %lld\n",
	(long long) sb.st_blocks);

	printf("Last status change       : %s", ctime(&sb.st_ctime));
	printf("Last file access         : %s", ctime(&sb.st_atime));
	printf("Last file modification   : %s\n", ctime(&sb.st_mtime));

	return 0;
}

