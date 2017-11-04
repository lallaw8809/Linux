/* Program for execl()
 * Author : Lal Bosco Lawrence   
 * Date   : 04-Nov-2017
 */

#include<stdio.h>
#include<unistd.h>

/* Arguments are passed as a list of strings to the main() */

//#define METHOD_1
//#define METHOD_2

int main()
{
	/* Different ways for execl() */
#ifdef METHOD_1
	execl("/bin/cat","cat","execl.c",NULL);
#elif  defined(METHOD_2)
	execl("/bin/ls","ls","-il","execl.c",NULL);
#else
	execl("./cmd_line","Arg_1","Arg_2","Arg_3",NULL);
#endif
	printf("Failed\n");

	return 0;
}
