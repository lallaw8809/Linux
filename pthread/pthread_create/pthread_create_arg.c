/* Program to create a thread and pass the argument
 * author : Lal Bosco Lawrence   
 * Date   : 18-oct-2017
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

/* Thread fuction declaration */
void* thread_function(void *arg)
{
	printf("Enter into thread...\n");
	printf("Passed argument : %s\n",(char *) arg);
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t tid;

	if(argc != 2)
	{
		printf("Invalid argument...\n");
		printf("Usage : <./pthread_create> <string>\n");
		exit(-1);
	}
	/* Create a thread and pass the argument*/
	int ret = pthread_create(&tid,NULL,thread_function,argv[1]);
	/* Validation of thread creation */
	if(ret)
	{
		printf("Thread is not created\n");
		exit(-1);	
	}
	else
	{
		printf("Thread is sucessfully created\n");
	}
	
	/* wait until the created thread to terminate */
	pthread_join(tid, NULL);

	return 0;
}
