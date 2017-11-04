/* Program for execvp()
 * Author : Lal Bosco Lawrence   
 * Date   : 04-Nov-2017
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *const ps_argv[]={"ps","as",NULL};
	
	/* arguments are passed as an array */
	execvp(ps_argv[0], ps_argv);
	printf("Failed\n");

	return 0;
}
