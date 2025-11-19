#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

bool	isOpeningBracket(int c)
{
	if (c == '{' || c == '[' || c == '(')
		return (true);
	return (false);
}

bool	isClosingBracket(int c)
{
	if (c == '}' || c == ']' || c == ')')
		return (true);
	return (false);
}

bool	isClosed(int closing_b, int opening_b)
{
	printf("c_b:%c o_b:%c\n", closing_b, opening_b);
	if (opening_b == '(' && closing_b != ')')
		return (false);
	if (opening_b == '{' && closing_b != '}')
		return (false);
	if (opening_b == '[' && closing_b != ']')
		return (false);
	if (opening_b == 0)
		return (false);
	return (true);
}

int	backtrack_brackets(char *input, int opening_b, int index)
{
	while(input[index])
	{
		if (isOpeningBracket(input[index]))
		{
			index = backtrack_brackets(input, input[index], index + 1);
			if (index == -1)
				return (-1);
		}
		else if(isClosingBracket(input[index]))
		{
			if (isClosed(input[index], opening_b))
				return (index);
			return (-1);
		}
		index++;
	}
	if (opening_b != 0)
	{
		return(-1);
	}
	return (0);
}

// {((((()))))}
int main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	int i = 1;
	printf("%d\n", argc);
	while (argv[i])
	{
		if(backtrack_brackets(argv[i], 0, 0) == -1)
		{
			write(1, "Error\n", 6);
			// break ;
		}
		printf("\n\n");
		i++;
	}
	if (i == argc)
		write(1, "OK\n", 3);
	return (0);
}
