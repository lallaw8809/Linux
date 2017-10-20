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
 * open the pipe and write the data into new process and
 * print it on the terminal	
 * Example :
 *        echo "This is the message, going to write..." | od −c
 */

int main()
{
	FILE *fp;
	char buffer[BUFSIZ + 1];
	sprintf(buffer, "This is the message, going to write...\n");
	/* Open the pipe */
	fp = popen("od -c", "w");

	if (fp != NULL) 
	{
		/* send the message through the pipe */
		fwrite(buffer, sizeof(char), strlen(buffer), fp);
		pclose(fp);
		exit(EXIT_SUCCESS);
	}

	exit(EXIT_FAILURE);
}
