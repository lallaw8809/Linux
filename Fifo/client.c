/* Program for fifo_server 
 * Author : Lal Bosco Lawrence
 * Date   : 18-oct-2017
 */

#include<stdio.h> 
#include<fcntl.h>
#include<stdlib.h>

#define BUF_SIZE 128

void main()
{
	int fifo_server,fifo_client;
	char data[BUF_SIZE];
	int choice;

	/* Get the input fro the user */
	printf("Choose the request to be sent to server from options below");
	printf("\n\t\t Enter 1 to get the First Name \n \
	Enter 2 to get the Last Name \n \
	Enter 3 to get the Professional \n");
	scanf("%d",&choice);

	/* Open the file server */
	fifo_server=open("fifo_server",O_RDWR);
	if(fifo_server < 0) /* validation of file serevr */
	{
		printf("Error in open the serevr");
		exit(-1);
	}
	/* send the user request into server */
	write(fifo_server,&choice,sizeof(int));

	/* Open the file client */
	fifo_client=open("fifo_client",O_RDWR);
	if(fifo_client < 0)/* validation of file client */
	{
		printf("Error to open the client\n");
		exit(0);
	}

	/* Get the user input  from the serevr */
	read(fifo_client,data,BUF_SIZE);
	printf("\n ***Reply from server is %s\n",data);
	close(fifo_server);
	close(fifo_client);
}

