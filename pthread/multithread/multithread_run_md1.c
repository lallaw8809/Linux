/* Program to create multiple thread and pass the argument
 * All the thread is running in a parral
 * Author : Lal Bosco Lawrence   
 * Date   : 19-oct-2017
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

#define NUM_OF_THREAD 15
#define THREAD_RUN    6

/* Thread fuction declaration */
void* thread_function(void *arg)
{
	int index;

	/* Thread enter into a loop to run concurently */
	for(index=0;index<THREAD_RUN;index++)
	{
		printf("Thread : %d is running\n",*((unsigned int *)arg) );
		sleep(1);
	}
}

int main()
{
	pthread_t tid[NUM_OF_THREAD];
	int index = 0,ret;
	unsigned int thread_num[NUM_OF_THREAD] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	/* Create a thread */
	for(index=0;index<NUM_OF_THREAD;index++)
	{
		ret = pthread_create(&tid[index],NULL,thread_function,&thread_num[index]);
		/* Validation of thread creation */
		if(ret)
		{
			printf("\nThread %d is not created\n",(index+1) );
			exit(-1);	
		}
		else
		{
			printf("\nSucessfully created a thread %d \n",(index+1));
		}
	}

	/* wait until the created thread to terminate */
	for(index=0;index<NUM_OF_THREAD;index++)
		pthread_join(tid[index], NULL);

	return 0;
}
