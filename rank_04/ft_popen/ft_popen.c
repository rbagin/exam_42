#define _GNU_SOURCE

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define READ_END 0
#define WRITE_END 1

int ft_popen(const char *file, char *const argv[], char type)
{
	if (!file || !argv || (type != 'r' && type != 'w'))
		return -1;

	int pipefd[2];
	if (pipe(pipefd) == -1)
		return -1;

	pid_t pid = fork();
	if (pid == -1)
		return -1;

	if (pid == 0)
	{
		if (type == 'r')
		{
			close(pipefd[READ_END]);
			dup2(pipefd[WRITE_END], STDOUT_FILENO);
			close(pipefd[WRITE_END]);
		} else if(type == 'w')
		{
			close(pipefd[WRITE_END]);
			dup2(pipefd[READ_END], STDIN_FILENO);
			close(pipefd[READ_END]);
		}
		execvp(file, argv);
		exit(1);
	}
	if (type == 'r')
	{
		close(pipefd[WRITE_END]);
		return (pipefd[READ_END]);
	} else if(type == 'w')
	{
		close(pipefd[READ_END]);
		return (pipefd[WRITE_END]);
	}
	return -1;
}

/*	Assignment name  : ft_popen
	Expected files   : ft_popen.c
	Allowed functions: pipe, fork, dup2, execvp, close, exit
	--------------------------------------------------------------------------------------

	Write the following function:

	int ft_popen(const char *file, char *const argv[], char type);

	The function must launch the executable file with the arguments argv (using execvp).
	If type is 'r' the function must return a file descriptor connected to the output of the command.
	If type is 'w' the function must return a file descriptor connected to the input of the command.
	In case of error or invalid parameter the function must return -1.

	For example, the function could be used like that:

	int main()
	{
		int  fd;
		char *line;

		fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
		while ((line = get_next_line(fd)))
			ft_putstr(line);
		return (0);
	}


	int	main() {
		int	fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
		dup2(fd, 0);
		fd = ft_popen("grep", (char *const []){"grep", "c", NULL}, 'r');
		char	*line;
		while ((line = get_next_line(fd)))
			printf("%s", line);
	}
*/
int	main(int argc, char **argv)
{
	return (0);
}
