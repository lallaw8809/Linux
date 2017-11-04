/* Program for execle()
 * Author : Lal Bosco Lawrence   
 * Date   : 04-Nov-2017
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	/* Need to set the path */
	execle( "/bin/ls","ls","-lR",NULL,NULL);
	printf("Failed\n");
	return 0;
}
