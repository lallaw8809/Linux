/* Program for execv()
 * Author : Lal Bosco Lawrence   
 * Date   : 04-Nov-2017
 */

#include<stdio.h>
#include<unistd.h>

int main()
{
	char *args[] = {"./cmd_line","Arg_1","Arg_2",NULL};

	/* arguments are passed as an array */
	execv(args[0],args);
	
	printf("Failed\n");

	return 0;
}



