/* Program create a fifo_server and fifo_client file 
 * Author : Lal Bosco Lawrence
 * Date   : 18-oct-2017
 */

#include<stdio.h> 
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	int fd_file1,fd_file2;

	/* Create a fifo_server file */
	fd_file1 = mkfifo("fifo_server",0777); 

	/* Validation of file creation */
	if(fd_file1<0) {
	printf("Unable to create a fifo");
	exit(-1);
	}

	/* Create a fifo_client file */
	fd_file2 = mkfifo("fifo_client",0777);

	/* Validation of file creation */
	if(fd_file2<0) {
	printf("Unable to create a fifo");
	exit(-1);
	}

	printf("fifo's server and client is created successfuly\n");

	return 0;
}

