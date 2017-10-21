/* Program for barrier synchronization using pthread
 * Author : Lal Bosco Lawrence   
 * Date   : 20-oct-2017
 */

/*
 Approach:
	1) Create 4 threads and all the threads are going to initalize the global variable (id_values[4]).
	2) This global variable is used in all the threads
	3) So all the threads need to wait to complete global varibale initialization
	4) We can do this using barrier sychronization
	
  Procedure followed in the code
	1) Initialized the barrier with 4
	2) call the  barrier_wait() in all of the 4 threads
	3) Once the barrier_wait() gets called 4 times 
	4) It will destroy the barrier and proceed further
*/

#include <stdio.h> 
#include <pthread.h> 
#include <stdlib.h>

#define BARRIER_WAIT_COUNT 4
#define THREAD_COUNT       4

int id_value[THREAD_COUNT];
pthread_barrier_t our_barrier;

void *thread1();
void *thread2();
void *thread3();
void *thread4();
void error_message(int thread_id);

void main() 
{
	pthread_t thread[THREAD_COUNT];
	pthread_attr_t attr;
	int my_index;

	/* Barrier initialization */
	pthread_barrier_init(&our_barrier,NULL,BARRIER_WAIT_COUNT);

	/* Thraed 1 creation */
	if( pthread_create(&thread[0],NULL,&thread1,NULL) < 0)	
		error_message(1);

	/* Thraed 2 creation */
	if( pthread_create(&thread[1],NULL,&thread2,NULL) < 0)	
		error_message(2);

	/* Thraed 3 creation */
	if( pthread_create(&thread[2],NULL,&thread3,NULL) < 0)	
		error_message(3);

	/* Thraed 4 creation */
	if( pthread_create(&thread[3],NULL,&thread4,NULL) < 0)	
		error_message(4);

	/* Wait untill thread to terminate */
	for(my_index=0;my_index<THREAD_COUNT;my_index++)
		pthread_join(thread[my_index],NULL);

	/* Once pthread_barrier_wait has been called by THREAD_COUNT times, 
	   all the threads will continue their execution of program by 
	   destroying the barrier
	*/
	pthread_barrier_destroy(&our_barrier);
}

/* Thread 1 declaration */
void *thread1() 
{
	printf("Enter value for thread 1 :  ");
	scanf("%d",&id_value[0]);

	/* a thread can be made to wait by the barrier */
	pthread_barrier_wait(&our_barrier);
	
	/* This will exwcute after the affer the barrier wait*/
	printf("\nThread 1 is continue to executing after the barrier wait\n \
	          Values entered by the threads are : %d %d %d %d\n",\
	          id_value[0],id_value[1],id_value[2],id_value[3] );
}

/* Thread 2 declaration */
void *thread2() 
{
	sleep(2);
	printf("Enter value for thread 2 :  ");
	scanf("%d",&id_value[1]);

	/* a thread can be made to wait by the barrier */
	pthread_barrier_wait(&our_barrier);
	
	/* This will exwcute after the affer the barrier wait*/
	printf("\nThread 2 is continue to executing after the barrier wait\n \
	          Values entered by the threads are : %d %d %d %d\n",\
	          id_value[0],id_value[1],id_value[2],id_value[3] );
}

/* Thread 3 declaration */
void *thread3() 
{
	sleep(3);
	printf("Enter value for thread 3 :  ");
	scanf("%d",&id_value[2]);

	/* a thread can be made to wait by the barrier */
	pthread_barrier_wait(&our_barrier);
	
	/* This will exwcute after the affer the barrier wait*/
	printf("\nThread 3 is continue to executing after the barrier wait\n \
	          Values entered by the threads are : %d %d %d %d\n",\
	          id_value[0],id_value[1],id_value[2],id_value[3] );
}

/* Thread 4 declaration */
void *thread4()
{
	sleep(4);
	printf("Enter value for thread 4 :  ");
	scanf("%d",&id_value[3]);

	/* a thread can be made to wait by the barrier */
	pthread_barrier_wait(&our_barrier);
	
	/* This will exwcute after the affer the barrier wait*/
	printf("\nThread 4 is continue to executing after the barrier wait\n \
	          Values entered by the threads are : %d %d %d %d\n",\
	          id_value[0],id_value[1],id_value[2],id_value[3] );
}

/* Print the error message */
void error_message(int thread_id)
{
	printf("Unable to create a thread : %d\n",thread_id);
	exit(-1);
}

