/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filter.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbagin <rbagin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/04 13:57:15 by rbagin        #+#    #+#                 */
/*   Updated: 2025/11/05 13:59:17 by rbagin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Allowed funcrtions: write, read, strlen , memmem , memmove, malloc, calloc,
realloc, free, printf , fprintf, stdout, stderr.
the program should take one arg str.
Should read stdin and write all content read in stdout except that every
occurrance of str must be replaced by * (as many as the leght of str)
it should be tested with random buffer sizes , using a custom read funct.
therefore the buffer being set in your program will be filled with a different
number of chars each new call.
In case of error during a read or a malloc , you must write "error" followed by
the error message in the stderr and return 1.
*/

/*	Solution:
	1. I need to read and save all of the input from stdin(0) using memcpy
	2. I need to traverse the input and search for all occurences using memmem
	3. I need to make a printing function that will make sure to print out
		all of the output properly(print the input unless you find a match)
	4. error managment using stderr
*/

#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

char	*read_input(void)
{
	char	*input = NULL;
	int		read_bytes = 0;
	int		total_len = 0;
	char	buf[BUFFER_SIZE];
	char	*temp;

	while ((read_bytes = read(STDIN_FILENO, buf, BUFFER_SIZE)) > 0)
	{
		temp = realloc(input, total_len + read_bytes + 1);
		if (!temp)
		{
			free(input);
			fprintf(stderr, "error\n");
			return (NULL);
		}
		input = temp;
		memmove(input + total_len, buf, read_bytes);
		total_len += read_bytes;
		input[total_len] = '\0';
		read_bytes = 0;
	}
	if (read_bytes < 0)
	{
		free(input);
		fprintf(stderr, "error\n");
		return (NULL);
	}
	return (input);
}

void	print_stars(int len)
{
	int	i = 0;
	while (i < len)
	{
		write(1, "*", 1);
		i++;
	}
}

int	process_input(char *filter)
{
	int	filter_len = strlen(filter);
	char	*input = read_input();
	char	*current;
	char	*match;

	if(!input)
		return (1);
	current = input;
	while (*current)
	{
		match = memmem(current, strlen(current), filter, filter_len);
		if (match == current)
		{
			print_stars(filter_len);
			current += filter_len;
		}
		else
		{
			write(1, current, 1);
			current++;
		}
	}
	free(input);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1][0])
		return (1);
	return (process_input(argv[1]));
}
