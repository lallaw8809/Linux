/* Program to create multiple thread and pass the argument
 * All the thread is running in a parraly
 * Author : Lal Bosco Lawrence   
 * Date   : 19-oct-2017
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

#define NUM_OF_THREAD 3
#define THREAD_RUN    6

/* Thread fuction declaration */
void* thread_function(void *arg)
{
	int index;

	/* Thread enter into a loop to run concurently */
	for(index=1;index<THREAD_RUN;index++)
	{	
		printf("Thread : %d is running \n",*((unsigned int *)arg));
		sleep(1);
	}

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

	return 0;
}
