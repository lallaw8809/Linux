#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SEGMENT_SIZE  100
#define STRING            "Hello World"
#define KEY               1234

void error_message(char *message);

void main()
{
	int shmid;
	key_t key = KEY;
	char *shm;

	/* Allocate a shared memory segment.  */ 
	if( (shmid=shmget(key,SHM_SEGMENT_SIZE,IPC_CREAT|0777) ) < 0 )
		error_message("shmget failed\n");

	/* Attach the shared memory segment.  */ 
	shm = shmat(shmid,NULL,0);
	if(shm == (char*)-1)
		error_message("shmat failed\n");
	printf ("shared memory attached at address %p\n", shm); 

	/* write the data into the memory */
	memcpy(shm,STRING,strlen(STRING));
#if 0
	/* Temporary pointer to write the Null character */
	char *ptr = shm;
	ptr += strlen(STRING);
	*ptr = '\0';
#endif
	/* read the shared memory */
	while(*shm != '*');

	/* free the memory segment */
	//shmctl(shmid,IPC_RMID,0);
}

void error_message(char *message)
{
	printf("%s\n",message);
	exit(-1);
}
