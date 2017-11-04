/****************************************************
 * Program to waitpid()
 * Author : Lal Bosco Lawrence   
 * Date   : 29-oct-2017
 ***************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* In fork, Parent will execute first and followed by child will execute
 * Parent do not wait, child to complete its execution
 * 
 * By using waitpid() API,We can make Parent to wait for child to complete its
 * execution
 */

void  err_msg(char *msg);

int main()
{
	int status;
	pid_t pid;

	/* Create a process */
	   if ((pid = fork()) < 0) {
        	err_msg("fork error");
	}

	/* Child process */
	if(pid == 0){
		sleep(5);
		printf("Child Process [Return value is 0]\n");
		printf("	PID  : %d\n",getpid() );
		printf("	PPID : %d\n",getppid() );
		printf("Child End\n\n");
	}
	else{ /* Parent process */
		printf("Parent Process [Return value is child PID]\n");
		printf("	PID  : %d\n",getpid() );
		printf("	PPID : %d\n",getppid() );
		
		printf("I am a parent, waiting for child to end...\n\n");

		/* waiting to child to complete its execution
                 * Make the parent to wait using child pid
		 * [ pid == child_pid ]	
		 */
		if (waitpid(pid, &status, 0) != pid)
			err_msg("waitpid error\n"); 

		printf("Parent End\n");
	}

	return 0;
}

/* Print the error message */
void  err_msg(char *msg)
{
	printf("%s\n",msg);
	exit(-1);
}


