/* Program for execvpe()
 * Author : Lal Bosco Lawrence   
 * Date   : 04-Nov-2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	/* Get the current path */
	char *path = getenv("PATH");
	char  pathenv[strlen(path) + sizeof("PATH=")];
	sprintf(pathenv, "PATH=%s", path);
	/* Append the NULL */
	char *envp[] = {pathenv, NULL};

	char *tests[] = {"Arg_1", "Arg_2","Arg_3",NULL};
	/* execvpe searches the cmd_line(bin) in the envp (PATH) */
	execvpe("./cmd_line", tests, envp);

	return 0;
}
