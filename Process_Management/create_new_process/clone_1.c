/****************************************************
 * Program to create a new process (child process) 
 * using clone system calls
 *
 * Author : Lal Bosco Lawrence
 * Date   : 29-oct-2017
 ****************************************************/

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>
#include <signal.h>

#define STACK_SIZE (1024*1024)
#define STRING_MSG "Child PID "

/* Function call for child process */
int child_process(void *arg)
{
	int index = 5;
	while(index--)
	{
		printf("%s = %d\n",(char*)arg,getpid());
		sleep(1);
	}
	
	return 0;
}

int main() 
{
	char* child_stack;
	pid_t pid;

	/* Print the Parent process PID */
	printf("Parent pid = %d\n",getpid());
	/* Stack memory allcoation for child */
	child_stack = malloc(STACK_SIZE);
	if(!child_stack){
		printf("Unable to allocate a stack memeory\n");
		exit(0);
	}

	/* Create a new process using clone */
	/* If CLONE_VFORK is set, the execution of the calling process is suspended 
		until the child releases its virtual memory resources */
	pid = clone(&child_process, (char *)child_stack+STACK_SIZE, CLONE_VM|CLONE_VFORK,(void*) STRING_MSG);
	/* Validation of a clone */
	if(pid < 0){
		printf("Clone is failed\n");
		exit(-1);
	}
	
	printf("Clone return value (Child PID) = %d\n",pid);

	/* De-allocate the memory */
	free(child_stack);

	return 0;
}
