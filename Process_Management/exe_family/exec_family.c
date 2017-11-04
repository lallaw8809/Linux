/* Program for exec_family()
 * Author : Lal Bosco Lawrence   
 * Date   : 04-Nov-2017
 */

/* Exec : Repalce the current progam the new program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void validation_of_input(char*);

int main(int argc, char *argv[])
{
	char *args[] = {"./cmd_line","Arg_1","Arg_2",NULL};

	/* Validation of input */
	if(argc != 2)
	{
		validation_of_input(argv[0]);
	}

	/* Validation of execl() */
	if( strcmp(argv[1],"execl") == 0 )
	{
		printf("Executing execl() ...\n");
		printf("Display the execl.c on TERMINAL..\n");
		sleep(2);
		execl("/bin/cat","cat","execl.c",NULL);
	}
	/* Validation of execlp() */
	else if( strcmp(argv[1],"execlp") == 0 )
	{
		printf("Executing execlp() ...\n");
		printf("Execute the cmd_line program...\n");
		sleep(2);
		execlp("./cmd_line","one","two","three","four",NULL);
	}
	/* Validation of execle() */
	else if( strcmp(argv[1],"execle") == 0 )
	{
		printf("Executing execle() ...\n");
		printf("Print the lsit of file on SCREEN...\n");
		sleep(2);
		execle( "/bin/ls","ls","-lR",NULL,NULL);
	}
	/* Validation of execv() */
	else if( strcmp(argv[1],"execv") == 0 )
	{
		printf("Executing execv() ...\n");
		printf("Execute the cmd_line program...\n");
		sleep(2);
		execv(args[0],args);
	}
	/* Validation of execvp() */
	else if( strcmp(argv[1],"execvp") == 0 )
	{
		printf("Executing execvp() ...\n");
		printf("Execute the cmd_line program...\n");
		sleep(2);
		execvp(args[0],args);
	}
	/* Validation of execvpe() */
	else if( strcmp(argv[1],"execvpe") == 0 )
	{
		printf("Executing execvpe() ...\n");	
		printf("Execute the cmd_line program...\n");
		sleep(2);
		/* Get the current path */
		char *path = getenv("PATH");
		char  pathenv[strlen(path) + sizeof("PATH=")];
		sprintf(pathenv, "PATH=%s", path);
		/* Append the NULL */
		char *envp[] = {pathenv, NULL};

		char *tests[] = {"Arg_1", "Arg_2","Arg_3",NULL};
		/* execvpe searches the cmd_line(bin) in the envp (PATH) */
		execvpe("./cmd_line",args , envp);
	}
	else
	{
		validation_of_input(argv[0]);
	}

	printf("Failed\n");

	return 0;
}

/* Error message for invlaid input */
void validation_of_input(char *input)
{
	printf("Invalid command...\n");
	printf("Usage : <%s> < execl | execlp | execle",input);
	printf(" | <execv | execvp | execvpe >\n");
	exit(-1);
}
