#define _GNU_SOURCE

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int	picoshell(char **cmds[])
{
	
}

/*
	Assignment name:	picoshell
	Expected files:		picoshell.c
	Allowed functions:	close, fork, wait, exit, execvp, dup2, pipe
	___________________________________________________________________

	Write the following function:

	int    picoshell(char **cmds[]);

	The goal of this function is to execute a pipeline. It must execute each
	commands of cmds and connect the output of one to the input of the
	next command (just like a shell).
	e
	Cmds contains a null-terminated list of valid commands. Each rows
	of cmds are an argv array directly usable for a call to execvp. The first
	arguments of each command is the command name or path and can be passed
	directly as the first argument of execvp.

	If any error occur, The function must return 1 (you must of course
	close all the open fds before). otherwise the function must wait all child
	processes and return 0. You will find in this directory a file main.c which
	contain something to help you test your function.*/
int	main(int argc, char **argv)
{
	return (0);
}
