/*******************************************************
 * Program to shared memory server
 * 	Write the data into shared memory
 * 	Waiting for the client update in a shared memory
 *      Once client update has done, kill the server
 *
 * Author : Lal Bosco Lawrence   
 * Date   : 20-oct-2017 
 ********************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SEGMENT_SIZE  100
#define STRING            "Hello Client"
#define KEY               1234
#define TERMINATE_SERVER  '*'
#define PERMISSION	  0777

void error_message(char *message);

void main()
{
	int shmid;
	key_t key = KEY;
	char *shm;

	/* Allocate a shared memory segment.  */ 
	if( (shmid=shmget(key,SHM_SEGMENT_SIZE,IPC_CREAT|PERMISSION) ) < 0 )
		error_message("shmget failed\n");

	/* Attach the shared memory segment.  */ 
	shm = shmat(shmid,NULL,0);
	if(shm == (char*)-1)
		error_message("shmat failed\n");

	/* write the data into the memory */
	memcpy(shm,STRING,strlen(STRING));

	/* read the shared memory */
	printf("waiting for the client update.....\n");
	while(*shm != TERMINATE_SERVER);

	/* free the memory segment 
	 * comment this, If you wanna see the assigned shared
	 * from terminal 
  	 */
	shmctl(shmid,IPC_RMID,0);
}

/* Print the error message */
void error_message(char *message)
{
	printf("%s\n",message);
	exit(-1);
}
