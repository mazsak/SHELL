#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "function.h"

#define N 64

int execute(char **args);
void process(char **args);

int execute(char **args){
	int status;
	pid_t pid;

	pid = fork ();
	if (pid == 0)
	{
		execvp (args[0], args);
		exit (EXIT_FAILURE);
	} else if (pid < 0){
		status = -1;
	} else{
		if (waitpid (pid, &status, 0) != pid){
			status = -1;
		}
	}
	return status;
}

void process(char **args){
	pid_t idprocess, idsession;
	idprocess = fork();
	if(idprocess < 0){
		exit(EXIT_FAILURE);
	}
	if(idprocess > 0){
		exit(EXIT_SUCCESS);
	}
	umask(0);
	idsession = setsid();
	if(idsession < 0){
		exit(EXIT_FAILURE);
	}
	if((chdir("/")) < 0){
		exit(EXIT_FAILURE);
	}
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	execute(args);

	exit(EXIT_SUCCESS);
}
