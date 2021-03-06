/*****************************************************
 * Program to shared memory client
 * 	Read the shared memory
 * 	Update the shared memory to kill the server
 *
 * Author : Lal Bosco Lawrence   
 * Date   : 20-oct-2017 
 ******************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SEGMENT_SIZE  100
#define KEY               1234
#define TERMINATE_SERVER  '*'
#define PERMISSION	  0777

void error_message(char *message);
void main()
{
	int shmid;
	key_t key = KEY;
	char *shm;
	char *ptr;

	/* Allocate a shared memory segment.  */ 
	if( (shmid=shmget(key,SHM_SEGMENT_SIZE,PERMISSION) ) < 0 )
		error_message("shmget failed\n");

	/* Attach the shared memory segment.  */ 
	shm = shmat(shmid,NULL,0);
	if(shm == (char*)-1)
		error_message("shmat failed\n");
	printf ("shared memory attached at address %p\n", shm);

	/* Read the shared memory and print it on the terminal */
	ptr = shm;
	while(*ptr != '\0')
		printf("%c",*ptr++);
	printf("\n");

	/* write it on shared memory to kill the server */
	*shm = TERMINATE_SERVER;
}

/* Print the error message */
void error_message(char *message)
{
	printf("%s\n",message);
	exit(-1);
}
