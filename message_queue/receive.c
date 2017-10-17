/* Message Queue Sample code to receive data from sender
 * Author : Lal Bosco Lawrence
 */

#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<string.h>
#include <stdlib.h>

#define BUF_LEN 128

struct msgbuf {
	long mtype;       /* message type, must be > 0 */
	char mtext[BUF_LEN];    /* message data */
};

/* print the error message */
void error_meassage(char *p)
{
	printf("%s\n",p);
	exit(0);
}

void main()
{
	key_t key = 1324;
	int msgid;
	struct msgbuf data;
	int index;

	/* Create a message queue*/
	if( msgid = msgget(key, 0666) < 0 ){
		error_meassage("Failed to open a message queue\n");
	}

	/* Append the message one by one into a queue */
	for(index=1;index<5;index++)
	{
		/* Receive the messgae */
		if( msgrcv(msgid, &data, BUF_LEN, (long) index, 0) < 0){
			error_meassage("Failed to receive a message\n");	
		}

		/* Print the received message on the terminal */
		printf("Received message : %s\n",data.mtext);
		
	}

	/* Delete the message queue */
	//msgctl(msgid,IPC_RMID, NULL);
}

