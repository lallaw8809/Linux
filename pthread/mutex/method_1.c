/* Program to add the sum using mutex
 * 
 * Author : Lal Bosco Lawrence   
 * Date   : 19-oct-2017
 */

/*
  Approach:
	*) Create 5 differnet pthread with same thread_function_name	
	*) and all of the 5 thread's tries to access the common resource at the same time
	*) Avoid the common resource corruption using mutex	
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

#define NUM_OF_THREAD 3
#define THREAD_RUN    6
#define COUNT         6
int sum = 0;

/* Mutex initialization */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

/* Thread fuction declaration */
void* thread_function(void *arg)
{
	int index;
	
	/* Lock the resource using mutex */
 	pthread_mutex_lock(&mutex); 

	/* CRITICAL SECTION : Multiple threads are using this resource */
	/* Thread enter into a loop to run concurently */
	for(index=1;index<COUNT;index++)
	{	
		sum += index;
		printf("Thread : %d is running : sum : %d index : %d\n",*((unsigned int *)arg),sum,index );
		sleep(1);
	}

	/* Unock the resource using mutex */
 	pthread_mutex_unlock(&mutex); 
}

int main()
{
	pthread_t tid[NUM_OF_THREAD];
	int index = 0;
	unsigned int thread_num[NUM_OF_THREAD] ;

	/* Feed the thread count */
	for(index=0;index<NUM_OF_THREAD;index++)
		thread_num[index] = index+1;

	/* Create a thread */
	for(index=0;index<NUM_OF_THREAD;index++)
	{
		if( pthread_create(&tid[index],NULL,thread_function,&thread_num[index]) < 0 )
		{
			printf("\nThread %d is not created\n",(index+1) );
			exit(-1);	
		}
	}

	/* wait until the created thread to terminate */
	for(index=0;index<NUM_OF_THREAD;index++)
		pthread_join(tid[index], NULL);

	printf("Total = %d\n",sum);

	return 0;
}
