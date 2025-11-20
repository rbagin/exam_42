#include <unistd.h>
#include <stdbool.h>

bool	tagsMatch(char *input, int open_start, int close_start)
{
	int j = open_start + 1;
	int i = close_start + 2;
	while (input[i] && input[i] != '>' && input[j] && input[j] != '>')
	{
		if (input[i] != input[j])
			return (false);
		i++;
		j++;
	}
	return (input[i] == '>' && input[j] == '>');
}

bool	isOpeningTag(char *input, int *index)
{
	int start = *index;
	if (input[start] != '<')
		return (false);
	if (input[start + 1] == '/')
		return (false);
	while (input[*index] && input[*index] != '>')
		(*index)++;
	if (input[*index] != '>')
		return (false);
	return (true);
}

bool	isClosingTag(char *input, int *index)
{
	int start = *index;
	if (input[start] != '<' || input[start + 1] != '/')
		return (false);
	while (input[*index] && input[*index] != '>')
		(*index)++;
	if (input[*index] != '>')
		return (false);
	return (true);
}

int	backtrack_tags(char *input, int index, int open_start)
{
	while (input[index])
	{
		if (input[index] == '<' && input[index + 1] != '/')
		{
			int	tag_start = index;
			if (isOpeningTag(input, &index))
			{
				index = backtrack_tags(input, index + 1, tag_start);
				if (index == -1)
					return (-1);
				index++;
			}
		}
		else if (input[index] == '<' && input[index + 1] == '/')
		{
			if (open_start < 0 || !tagsMatch(input, open_start, index))
				return (-1);
			while (input[index] && input[index] != '>')
				index++;
			return (index);
		}
		else
			index++;
	}
	if (open_start >= 0)
		return (-1);
	return (index);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	int i = 1;
	while (argv[i])
	{
		if (backtrack_tags(argv[i], 0, -1) == -1)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	if (i == argc)
		write(1, "OK\n", 3);
	return (0);
}
