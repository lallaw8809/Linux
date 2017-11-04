/****************************************************
 * Program for zombie state
 * Author : Lal Bosco Lawrence   
 * Date   : 29-oct-2017
 ***************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* In fork, Parent will execute first and followed by child will execute
 * Parent do not wait, child to complete its execution
 * 
 * Parent exit before child end and child become an orfan
 * Child enters into a zombie state
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
		
		printf("Parent is End, before child end \n");
		printf("Child will be a orfan now and enters into Zombie state\n");
	}

	return 0;
}

