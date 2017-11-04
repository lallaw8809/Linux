/****************************************************
 * Program to wait() using fork()
 * Author : Lal Bosco Lawrence   
 * Date   : 29-oct-2017
 ***************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* In fork, Parent will execute first and followed by child will execute
 * Parent do not wait, child to complete its execution
 * 
 * By using wait API,We can make Parent to wait for child to complete its
 * execution
 */
int main()
{
	int status;

	/* Create a process */
	pid_t pid = fork();

	/* Child process */
	if(pid == 0)
	{
		sleep(5);
		printf("Child Process [Return value is 0]\n");
		printf("	PID  : %d\n",getpid() );
		printf("	PPID : %d\n",getppid() );
		printf("Child End\n\n");
	}
	else /* Parent process */
	{
		printf("Parent Process [Return value is child PID]\n");
		printf("	PID  : %d\n",getpid() );
		printf("	PPID : %d\n",getppid() );
		
		printf("I am a parent, waiting for child to end...\n\n");

		/* waiting to child to complete its execution
		 * [ waitpid(-1, &status, 0) equivalent to wait(&status) ]	
		 */
		wait(&status);  
		
		printf("Parent End\n");
	}

	return 0;
}


