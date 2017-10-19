/* Program to create multiple thread and pass the argument
 * All the thread is running in a parral
 * Author : Lal Bosco Lawrence   
 * Date   : 19-oct-2017
 */

#include <stdio.h> 
#include <pthread.h> 
#include <stdlib.h>

#define NUM_OF_THREAD 5
#define THREAD_RUN    6

void *thread1() ;
void *thread2() ;
void *thread3() ;
void *thread4() ;
void *thread5() ;

void main() 
{
	pthread_t thread_id[NUM_OF_THREAD];
	int ret,i=0;

	/* Thread 1 creation */
	ret = pthread_create(&thread_id[0],NULL,&thread1, NULL);
	if(ret != 0)
	{
		printf("Unable to create thread1");
	}


	/* Thread 2 creation */
	ret = pthread_create(&thread_id[1],NULL,&thread2,NULL);
	if(ret != 0)
	{
		printf("Unable to create thread2");
	}

	/* Thread 3 creation */
	ret = pthread_create(&thread_id[2],NULL,&thread3, NULL);
	if(ret != 0)
	{
		printf("Unable to create thread3");
	}
	/* Thread 4 creation */
	ret = pthread_create(&thread_id[3],NULL,&thread4, NULL);
	if(ret != 0)
	{
		printf("Unable to create thread4");
	}
	/* Thread 5 creation */
	ret = pthread_create(&thread_id[4],NULL,&thread5, NULL);
	if(ret != 0)
	{
		printf("Unable to create thread5");
	}

	/* wait until the created thread to terminate */
	for(i=0;i<NUM_OF_THREAD;i++)
		pthread_join(thread_id[i],NULL);
}

/* Thread 1 declaration */
void *thread1() 
{
	int index = 0;
	for(index=0;index<THREAD_RUN;index++)
	{
		printf("Thread 1 is running...\n");
		sleep(1);
	}
}

/* Thread 2 declaration */
void *thread2() 
{
	int index = 0;
	for(index=0;index<THREAD_RUN;index++)
	{
		printf("Thread 2 is running...\n");
		sleep(1);
	}
}

/* Thread 3 declaration */
void *thread3() 
{
	int index = 0;
	for(index=0;index<THREAD_RUN;index++)
	{
		printf("Thread 3 is running...\n");
		sleep(1);
	}
}

/* Thread 4 declaration */
void *thread4() 
{
	int index = 0;
	for(index=0;index<THREAD_RUN;index++)
	{
		printf("Thread 4 is running...\n");
		sleep(1);
	}
}

/* Thread 5 declaration */
void *thread5() 
{
	int index = 0;
	for(index=0;index<THREAD_RUN;index++)
	{
		printf("Thread 5 is running...\n");
		sleep(1);
	}
}


