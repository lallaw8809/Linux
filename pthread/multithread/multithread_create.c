/* Program to create multiple thread and pass the argument
 * Author : Lal Bosco Lawrence   
 * Date   : 19-oct-2017
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

#define NUM_OF_THREAD 5

/* Thread fuction declaration */
void* thread_function(void *arg)
{
	printf("	Enter into the thread and thread id : %d\n\n",*((unsigned int *)arg) );

	/* exit the thread */
	pthread_exit(NULL);

	return NULL;
}

int main()
{
	pthread_t tid[NUM_OF_THREAD];
	int index = 0,ret;

	/* Create a 5 thread */
	for(;index<NUM_OF_THREAD;index++)
	{
		ret = pthread_create(&tid[index],NULL,thread_function,&index);
		/* Validation of thread creation */
		if(ret)
		{
			printf("\nThread %d is not created\n",index);
			exit(-1);	
		}
		else
		{
			printf("\nSucessfully created a thread %d \n",index);
		}
	
		/* wait until the created thread to terminate */
		pthread_join(tid[index], NULL);
	}

	return 0;
}
