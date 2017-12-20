/*****************************************************************************
 * Pipe   : Communication between processes [Parent and child : Full duplex] 
 *          
 * Author : Lal Bosco Lawrence   
 * Date   : 19-oct-2017
 *****************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 50
#define FD_SIZE   2

void error_message(char *message);

int main(char argc, char *argv[])
{
        int     fd_1[FD_SIZE],fd_2[FD_SIZE];
        pid_t   pid;
        char    readbuffer[BUF_SIZE];

	/* Validation of  the input */
	if(argc != 3)
	{
		printf("Invalid command...\n");
		printf("Usage   : <./one_pipe>  <msg_to_parent> <msg_to_child>\n");
		printf("Example : ./one_chile   'Hello Parent'  'Hello child'  \n");
		exit(-1);	
	}

	/* Create a pipe
	 * Child to Parent : fd_1[1] : Write, fd_1[0] : read 
	 * Parent to Child : fd_2[1] : Write, fd_2[0] : read 
	 */
        pipe(fd_1); pipe(fd_2);
        
	/* Crate a new process */ 
        if((pid = fork()) == -1)
		error_message("Fork failed");

        if(pid == 0) /* Child process */
        {
                /* Child process closes up pipe  */
                close(fd_1[0]); close(fd_2[1]);

                /* Send a mesage into parent */
                if( write(fd_1[1], argv[1], (strlen(argv[1])+1)) < 0)
			error_message("Child : Write is failed");
		
		/* read the message from parent */
		if( read(fd_2[0], readbuffer, sizeof(readbuffer)) < 0)
			error_message("Child : Read is failed");

                printf("Child Received string  : %s\n", readbuffer);
        }
        else /* Parent process */
        {
                /* Parent process close the pipe */
                close(fd_1[1]); close(fd_2[0]);

	        /* Send a message into the child */
                if( write(fd_2[1], argv[2], (strlen(argv[2])+1)) < 0)
			error_message("Parent : Write is failed");

                /* Read a message from child */
                if( read(fd_1[0], readbuffer, sizeof(readbuffer)) < 0)
			error_message("Parent : Write is failed");

                printf("Parent Received string : %s\n", readbuffer);
        }
        
        return 0;
}

/* Print the erroe message */
void error_message(char *message)
{
	printf("%s\n",message);
	exit(-1);
}
