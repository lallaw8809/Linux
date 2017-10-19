/* Program to add the sum using mutex
 * All the thread is running in a parral
 * Author : Lal Bosco Lawrence   
 * Date   : 19-oct-2017
 */

/*
  Approach:
	*) Create 5 differnet pthread with different thread_function_name	
	*) and all of the 5 thread's tries to access the common resource at the same time
	*) Avoid the common resource corruption using mutex	
*/

#include <stdio.h> 
#include <pthread.h> 
#include <stdlib.h>

#define NUM_OF_THREAD 5
#define THREAD_RUN    6

int sum = 0;

/* Mutex initialization */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread1() ;
void *thread2() ;
void *thread3() ;
void *thread4() ;
void *thread5() ;
void error_message(int error);
void critical_section(int thread);

void main() 
{
	pthread_t thread_id[NUM_OF_THREAD];
	int i=0;

	/* Thread 1 creation */
	if( pthread_create(&thread_id[0],NULL,&thread1, NULL) < 0 ) 
		error_message(1);

	/* Thread 2 creation */
	if( pthread_create(&thread_id[1],NULL,&thread2,NULL) < 0 ) 
		error_message(2);

	/* Thread 3 creation */
	if( pthread_create(&thread_id[2],NULL,&thread3, NULL) < 0 ) 
		error_message(3);

	/* Thread 4 creation */
	if( pthread_create(&thread_id[3],NULL,&thread4, NULL) < 0 ) 
		error_message(4);

	/* Thread 5 creation */
	if( pthread_create(&thread_id[4],NULL,&thread5, NULL) < 0 ) 
		error_message(5);

	/* wait until the created thread to terminate */
	for(i=0;i<NUM_OF_THREAD;i++)
		pthread_join(thread_id[i],NULL);

	printf("Total + %d\n",sum);
}

/* Critical section code */
void critical_section(int thread)
{
	int index;

	/* CRITICAL SECTION : Multiple threads are using this resource */
	for(index=1;index<THREAD_RUN;index++)
	{
		sum += index;
		printf("Thread %d is running...  : sum : %d index : %d\n",thread, sum,index);
		sleep(1);
	}
}

/* Thread 1 declaration */
void *thread1() 
{
 	pthread_mutex_lock(&mutex); /* Lock the resource using mutex */
	critical_section(1);
 	pthread_mutex_unlock(&mutex); /* Unock the resource using mutex */
}

/* Thread 2 declaration */
void *thread2() 
{
 	pthread_mutex_lock(&mutex); /* Lock the resource using mutex */
	critical_section(2);
 	pthread_mutex_unlock(&mutex); /* Unock the resource using mutex */
}

/* Thread 3 declaration */
void *thread3() 
{
 	pthread_mutex_lock(&mutex); /* Lock the resource using mutex */
	critical_section(3);
 	pthread_mutex_unlock(&mutex); /* Unock the resource using mutex */
}

/* Thread 4 declaration */
void *thread4() 
{
 	pthread_mutex_lock(&mutex); /* Lock the resource using mutex */
	critical_section(4);
 	pthread_mutex_unlock(&mutex); /* Unock the resource using mutex */ 
}

/* Thread 5 declaration */
void *thread5() 
{
 	pthread_mutex_lock(&mutex); /* Lock the resource using mutex */
	critical_section(4);
 	pthread_mutex_unlock(&mutex); /* Unock the resource using mutex */
}

/* Print the error message */
void error_message(int error)
{
	printf("Unable to create thread : %d\n",error);
	exit(-1);
}

