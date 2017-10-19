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
	while(1){
		printf("Enter into the thread : %d\n",*((int *) arg));
		sleep(1);
		/* Exit the loop */
		pthread_exit(NULL);
	}
	return NULL;
}

int main()
{
	pthread_t tid;
	int val = 999;

	/* Create a thread and pass the argument*/
	int ret = pthread_create(&tid,NULL,thread_function,&val);
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
