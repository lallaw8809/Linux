/* Program to create a daemon process and run it in background
 * author : Lal Bosco Lawrence   
 * Date   : 18-oct-2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*Daemon Process
 *	daemon is a computer program that runs as a background process	
 */

void main()
{
	int fd;

	/* Create a new process */
	pid_t pid = fork();

	// Indication of fork() failure
	if (pid < 0)
	{
		printf("fork failed!\n");
		/* Return failure in exit status */
		exit(-1);
	}

	/* Child process 
	   Making the child process as deamon	
	   Procedure: Set a new section	 	
	*/
	if(pid == 0)
	{
		/* set new session */
		if(setsid() < 0)
		{
			printf("Failed to set a new section");
			// Return failure
			exit(-1);
		}
		
		/* create a file and open the file to write in the background */
		if( (fd = open("daemon.txt",O_CREAT | O_APPEND | O_WRONLY,0777)) < 0)
		{
			printf("Failed to creat a file\n");
			exit(0);
		}
		
		/* Write a text into a file in background */
		while(1)
		{
			write(fd,"Daemon process....\n",20);
			sleep(1);		
		}

		close(fd);		
	}
}

