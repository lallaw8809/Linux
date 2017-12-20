/*****************************************************************************
 * Pipe   : Communication between processes [Parent and child : Half duplex] 
 *          Write it on the child and read it on the parent
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

int main(int argc, char *argv[])
{
        int     fd[FD_SIZE ];
        pid_t   pid;
        char    readbuffer[BUF_SIZE];

	/* Validation of  the input */
	if(argc != 2)
	{
		printf("Invalid command...\n");
		printf("Usage   : <./one_pipe> <message>\n");
		printf("Example : ./one_child 'hello child' \n");
		exit(-1);	
	}

	/* Create a pipe
	 * fd[1] : Write
	 * fd[0] : read
	 */
        pipe(fd);

	/* Crate a new process */        
        if((pid = fork()) == -1)
		error_message("Fork failed");

	/* Child process */
        if(pid == 0)
        {
                /* Child process closes up input side of pipe */
                close(fd[0]);

                /* Send "string" through the output side of pipe */
                if( write(fd[1], argv[1], (strlen(argv[1])+1)) < 0)
			error_message("Child : Write failed");

                exit(0);
        }
        else /* Parent process */
        {
	        /* Parent process closes up output side of pipe */
                close(fd[1]);

                /* Read in a string from the pipe */
                if(read(fd[0], readbuffer, sizeof(readbuffer)) < 0)
			error_message("Parent : Read failed");
		
                printf("Received message from child: %s\n", readbuffer);
        }
        
        return 0;
}

/* Print the erroe message */
void error_message(char *message)
{
	printf("%s\n",message);
	exit(-1);
}
