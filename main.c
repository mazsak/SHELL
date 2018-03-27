#include <stdio.h>
#include <stdlib.h>
#include "function.h"

#define N 64

int main(){
	int run = 1;
	char *make = (char *)malloc(N * sizeof(char));
	char **args;
	ssize_t buffer = N;
	system("clear");
	while(run){
		system("printf \"\033[94m \033[1m\"");
		system("echo `pwd` | tr -d '\n'");
		printf("\033[0m# ");
		getline(&make,&buffer, stdin);
		args = divide(make);
		run = multiply(args);
	}

	exit(EXIT_SUCCESS);
}
