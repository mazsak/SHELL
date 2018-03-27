#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "function.h"

#define N 64
#define SIGNS " \t\n\r\a"

char **divide(char *make);
int multiply(char **args);

char **divide(char *make){
	int a=0; 
	char **args = (char**)malloc(sizeof(char*)*N);
	args[0] = strtok(make, SIGNS);
	while(args[a] != NULL){
		a++;
		args[a] = strtok(NULL, SIGNS);
	}
	return args;
}

int multiply(char **args){
	int a = 0, i = 0, run = 1;
	char **argsfirst = (char**)malloc(sizeof(char*)*N);
	argsfirst[i] = args[a];
	while(args[a] != NULL){
		i++;
		if(args[a+1] != NULL){
			if(strcmp(args[a+1], "|") == 0){
				execute(argsfirst);
				i = -1;
				a++;
			}else if(strcmp(args[a+1], "&") == 0){
				process(argsfirst);
				i = -1;
				a++;
			}else if(strcmp(args[a], "cd") == 0){
				chdir(args[a+1]);
				i = -1;
				a++;
			}if(strcmp(args[a], "exit") == 0){
				return 0;
			}
		}
		a++;
		argsfirst[i] = args[a];
	}
	execute(argsfirst);
	return run;
}
