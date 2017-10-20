/*********************************************************************************
 * Pipe   : Program to pass the data between processes using popen() and pclose()
 * Author : Lal Bosco Lawrence   
 * Date   : 20-oct-2017
 *********************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>

/* The  popen()  function  opens a process by creating a pipe, forking, and invoking the shell. 
 * or pass data to or receive data from it.
 */

/* Approach
 * open the pipe and read the new process information 'uname -r' and
 * write it on the buffer and print it on the terminal	
 */
int main()
{
	FILE *fp;
	char buffer[BUFSIZ + 1];
	int read ;

	/* clear the buffer */
	memset(buffer, '\0', sizeof(buffer));
	

	fp = popen("uname -a", "r");
	if (fp != NULL) 
	{
		read = fread(buffer, sizeof(char), BUFSIZ, fp);
		if (read > 0) {
			printf("Output was:−\n%s\n", buffer);
		}

		pclose(fp);
		exit(EXIT_SUCCESS);
	}

	exit(EXIT_FAILURE);
}
