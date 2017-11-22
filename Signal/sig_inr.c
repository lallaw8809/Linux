#include <signal.h>
#include<stdio.h>
#include<stdlib.h>

//SIGINT for ctl+c

void SigIntHandler(int signum)
{
	printf("Signal Interrupt Handler %d\n",signum);
}

int main()
{
	//signal(SIGTERM, powerFailureHandler);
	signal(SIGINT, SigIntHandler);
	while(1);
	return 0;
}
