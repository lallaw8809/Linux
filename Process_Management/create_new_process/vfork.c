/* Program to create a new process using vfork (child process)
 * author : Lal Bosco Lawrence   
 * Date   : 18-oct-2017
 */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

/* vfork - create a child process and block parent
 * The basic difference between vfork and fork is that when a new process is created with vfork(), 
 * the parent process is temporarily suspended, and the child process might borrow the parent's address space.
 * This strange state of affairs continues until the child process either exits, 
 * or calls execve(), at which point the parent process continues. 
 */

void main()
{
	/* Create a process */
	pid_t pid = vfork();

	printf("\nvfork return value : %d\n",pid);

	/* Child process */
	if(pid == 0){
		printf("Child Process [Return value is 0]\n");
		printf("	PID  : %d\n",getpid() );
		printf("	PPID : %d\n\n",getppid() );
		exit(0);
	}
	else /* Parent process */
	{
		printf("Parent Process [Return value is child PID]\n");
		printf("	PID  : %d\n",getpid() );
		printf("	PPID : %d\n",getppid() );
	}
}

