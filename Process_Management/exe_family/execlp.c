/* Program for execlp()
 * Author : Lal Bosco Lawrence   
 * Date   : 04-Nov-2017
 */

#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	/* Arguments are passed as a list of strings */
	execlp("./cmd_line","one","two","three","four",NULL);
	printf("Failed\n");
	return 0;
}
