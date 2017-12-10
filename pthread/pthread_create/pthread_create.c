/* Program to create a thread
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
	/* Kill the thread */
	//pthread_exit(NULL);
}

int main()
{
	pthread_t tid;

	/* Create a thread */
	int ret = pthread_create(&tid,NULL,thread_function,NULL);
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

	/* Kill the thread */
	pthread_cancel(tid);

	return 0;
}
