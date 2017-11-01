#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>

main()
{
	int fd1,fd2;
	char buf[1023];

	fd1 = open("open.c",O_RDONLY,777);
	fd2 = dup(fd1);
	read(fd2,buf,1023);
	printf("%s",buf);

	close(fd1);
	close(fd2);
}
