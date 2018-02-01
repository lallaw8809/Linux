/**************************************
 * Program to show demo for semaphore
 * Author : Lal Bosco Lawrence   
 * Date   : 01-Feb-2018
 *************************************/
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/sem.h> 

/*************** Approach ************************
 Initialize a set of semaphore
 Initialize a semaphore resource (Num_of_sema = 1)
 Lock the resource (Press Enter key)
 Unlock the resource (Press Enter key)
****************************************************/

union semun {
	int              val;    /* Value for SETVAL */
	struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
	unsigned short  *array;  /* Array for GETALL, SETALL */
	struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
};

int main(void) 
{ 
	key_t key; 
	int semid; 
	union semun arg; 
	struct sembuf sb = {0, -1, 0};  /* set to allocate resource */

	if ((key = ftok("semaphore.c", 'J')) == -1) { 
	    perror("ftok"); 
	    exit(1); 
	} 
	/* create a semaphore set with 1 semaphore: */ 
	if ((semid = semget(key, 1, 0666 | IPC_CREAT)) == -1) { 
	    perror("semget"); 
	    exit(1); 
	} 
	/* initialize semaphore #0 to 1: */ 
	arg.val = 1; 
	if (semctl(semid, 0, SETVAL, arg) == -1) { 
	    perror("semctl"); 
	    exit(1); 
	} 

	printf("Press return to lock: "); 
	getchar(); 
	printf("Trying to lock...\n"); 
	if (semop(semid, &sb, 1) == -1) { 
	    perror("semop"); 
	    exit(1); 
	} 
	printf("Locked.\n");  

	printf("Press return to unlock: "); 
	getchar(); 
	sb.sem_op = 1; /* free resource */ 
	if (semop(semid, &sb, 1) == -1) { 
	    perror("semop"); 
	    exit(1); 
	} 
	printf("Unlocked\n"); 

	/* remove it: */ 
	if (semctl(semid, 0, IPC_RMID, arg) == -1) { 
		perror("semctl"); 
		exit(1); 
	} 

	return 0; 
} 

