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
	int choice;
	char buf[BUF_SIZE];
	while(1){
		/* Open the fifo server */
		fifo_server = open("fifo_server",O_RDWR);
		if(fifo_server<1) //Validation of opening the server
		{
			printf("Error opening serevr\n");
			exit(0);
		}
		/* Read the request from the server */
		read(fifo_server,&choice,sizeof(int));
		printf("The Entereed choice is %d\n",choice);

		/* Open the fifo client */
		fifo_client = open("fifo_client",O_RDWR);
		if(fifo_client<1) //Validation of opening the server
		 {
			printf("Error to open client\n");
			exit(0);
		}

		switch(choice) {
			//%[^\n]s to avoid the space
			case 1: //Get the first name from user
				printf("Enter your first name ?\n");
				scanf("%s",buf);
				write(fifo_client,buf,BUF_SIZE ); 
				printf("\n Data sent to client \n");
				break;

			case 2://Get the last name from user
				printf("Enter your last name ?\n");
				scanf("%s",buf);
				write(fifo_client,buf,BUF_SIZE ); 
				printf("\nData sent to client\n");
				break;

			case 3: //Get the professional i/f from user
				printf("Enter your professional ?\n");
				scanf("%s",buf); 
				write(fifo_client,buf,BUF_SIZE); 
				printf("\nData sent to client\n");
				break;

			default:
				printf("Invalid option\n");
				break;
		}

		/* Close the file server and client */
		close(fifo_server);
		close(fifo_client);
	}
}

