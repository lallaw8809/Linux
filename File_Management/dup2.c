#include <fcntl.h>              /* Obtain O_* constant definitions */
#include <unistd.h>
#include <unistd.h>
#include<stdio.h>

main()
{

 // int dup2(int oldfd, int newfd);
  //int dup3(int oldfd, int newfd, int flags);

	int fd1,fd2;
	char buf[1023];

	fd1 = open("open.c",O_RDONLY,777);
	dup2(fd1,fd2);  //(old,new)
	close(fd1);
	read(fd2,buf,1023);
	printf("%s",buf);

	
	close(fd2);
}

