#include <fcntl.h>              /* Obtain O_* constant definitions */
#include <unistd.h>
#include <unistd.h>
#include<stdio.h>

/*
DESCRIPTION

dup and dup2 create a copy of the file descriptor oldfd.
After successful return of dup or dup2, the old and new descriptors may
be used interchangeably. They share locks, file position pointers and
flags; for example, if the file position is modified by using lseek on
one of the descriptors, the position is also changed for the other.

The two descriptors do not share the close-on-exec flag, however.

dup uses the lowest-numbered unused descriptor for the new descriptor.

dup2 makes newfd be the copy of oldfd, closing newfd first if necessary.  

RETURN VALUE

dup and dup2 return the new descriptor, or -1 if an error occurred 
(in which case, errno is set appropriately). 
*/

main()
{

 // int dup2(int oldfd, int newfd);
  //int dup3(int oldfd, int newfd, int flags);

	int fd1,fd2;
	char buf[1023];

	fd1 = open("open.c",O_RDONLY,777);
	dup3(fd1,fd2);  //(old,new)
	read(fd2,buf,1023);
	printf("%s",buf);

	close(fd1);
	close(fd2);
}

