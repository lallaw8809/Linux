/* Message Queue Sample code to send the data into receiver
 * Author : Lal Bosco Lawrence
 */

#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

#define BUF_LEN         128
#define NUM_OF_MESSAGE    5
#define KEY            1234

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
	key_t key = KEY;
	int msgid;
	struct msgbuf data;
	int index;

	/* Create a message queue*/
	if( msgid = msgget(key, IPC_CREAT | 0666) < 0 ){
		error_meassage("Failed to create a message queue\n");
	}

	/* Append the message one by one into a queue */
	for(index=1;index<NUM_OF_MESSAGE+1;index++)
	{
		data.mtype = index;
		printf("Enter the data\n");
		scanf("%s",data.mtext);

		/* Send the messgae */
		if( msgsnd(msgid, &data, strlen(data.mtext)+1, IPC_NOWAIT) < 0){
			error_meassage("Failed to send a message\n");	
		}
	}
}

