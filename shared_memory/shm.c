/********************************************
 * Program to shared memory 
 * 	Shows that how to create a shared memory
 * 	how to access it
 *
 * Author : Lal Bosco Lawrence   
 * Date   : 20-oct-2017 
 ********************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/shm.h> 
#include <sys/stat.h>

#define SHM_SEGMENT_SIZE  100 /* bytes */
#define STRING            "Hello World"

void error_message(char *message);

int main()
{
	int shmid;
	char *shared_mem;
	struct shmid_ds buf;

	/* Create a shared memory segment */
	shmid = shmget(IPC_PRIVATE,SHM_SEGMENT_SIZE,IPC_CREAT|0777);
	if(shmid < 0)
		error_message("shmget is failed");

	/* To Attach for shared memory */
	shared_mem = shmat(shmid,NULL,0);
	if(shared_mem == (char*) -1)
		error_message("shmat is failed");
	printf("Shared Memory attached address space = %p\n",shared_mem);

	/* Write data into a shared memory */
	memcpy(shared_mem, STRING, strlen(STRING) );
	printf("%s\n",shared_mem);

	/* Determine the segment's size. */
	shmctl(shmid,IPC_STAT,&buf);
	printf("Size of the segment in bytes = %d\n", (int) buf.shm_segsz);

	/* Detach the shared memory segment.  */ 
	shmdt(shared_mem);

	/* Reattach the shared memory segment, at a different address.  */ 
	shared_mem = shmat(shmid,(void*) 0x5000000,0);
	if(shared_mem == (char*) -1)
		error_message("Reattached : shmat is failed");
	printf("Shared Mmemory re-attached address space = %p\n",shared_mem);

	/* Detach the shared memory segment.  */ 
	shmdt (shared_mem);

	/* Deallocate the shared memory segment.  */ 
	shmctl (shmid, IPC_RMID, 0);

	return 0;
}

/* Print the error message */
void error_message(char *message)
{
	printf("%s\n",message);
	exit(-1);
}
