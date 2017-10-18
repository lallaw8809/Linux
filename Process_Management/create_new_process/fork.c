/* Program to create a new process (child process)
 * author : Lal Bosco Lawrence   
 * Date   : 18-oct-2017
 */

#include<stdio.h>
#include <unistd.h>

/* fork - create a child process
 * The fork call basically makes a duplicate of the current process
 */
void main()
{
	/* Create a process */
	pid_t pid = fork();

	printf("\nFork return value : %d\n",pid);

	/* Child process */
	if(pid == 0){
		printf("Child Process [Return value is 0]\n");
		printf("	PID  : %d\n",getpid() );
		printf("	PPID : %d\n\n",getppid() );
	}
	else /* Parent process */
	{
		printf("Parent Process [Return value is child PID]\n");
		printf("	PID  : %d\n",getpid() );
		printf("	PPID : %d\n",getppid() );
	}
}

