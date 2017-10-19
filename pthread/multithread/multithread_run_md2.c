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
void error_message(int error);
void thread_runing(int thread_num);

void main() 
{
	pthread_t thread_id[NUM_OF_THREAD];
	int ret,i=0;

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
}

/* Thread 1 declaration */
void *thread1() 
{
	thread_runing(1);
}

/* Thread 2 declaration */
void *thread2() 
{
	thread_runing(2);
}

/* Thread 3 declaration */
void *thread3() 
{
	thread_runing(3);
}

/* Thread 4 declaration */
void *thread4() 
{
	thread_runing(4);
}

/* Thread 5 declaration */
void *thread5() 
{
	thread_runing(5);
}

/* Execute the thread */
void thread_runing(int thread_num)
{
	int index = 0;
	for(index=0;index<THREAD_RUN;index++)
	{
		printf("Thread %d is running...\n",thread_num);
		sleep(1);
	}
}

/* Print the error message */
void error_message(int error)
{
	printf("Unable to create thread : %d\n",error);
	exit(-1);
}

