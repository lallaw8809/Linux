
/* Program to print process ID's
 * author : Lal Bosco Lawrence   
 * Date   : 18-oct-2017
 */
#include<stdio.h>
#include <unistd.h>

void main()
{
	/* print process ID's */
	printf("PID of this process                : %d\n",getpid() );
	printf("PPID of this process               : %d\n",getppid() );
	printf("USER ID of this process            : %d\n",getuid() );
	printf("Effective User ID of this process  : %d\n",geteuid() );
	printf("Group ID of this process           : %d\n",getgid() );
	printf("Effective Group ID of this process : %d\n",getegid() );
}

