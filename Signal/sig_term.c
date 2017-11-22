#include <signal.h>
#include<stdio.h>
#include<stdlib.h>

//SIGTERM  for kill

void SigTermHandler(int signum)
{
	printf("Signal Term Handler %d\n",signum);
}

int main()
{
	signal(SIGTERM, SigTermHandler);
	while(1);
	return -1;
}
