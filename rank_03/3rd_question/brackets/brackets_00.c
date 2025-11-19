#include <unistd.h>
#include <stdbool.h>

bool	isOpeningB(char c)
{
	if (c == '[' || c == '(' || c == '{')
		return (true);
	return (false);
}

bool	isClosingB(char c)
{
	if (c == ']' || c == ')' || c == '}')
		return (true);
	return (false);
}

bool	isClosed(char closing_b , char opening_b)
{
	if (!opening_b)
		return (false);
	if (closing_b == '}' && opening_b != '{')
		return (false);
	if (closing_b == ']' && opening_b != '[')
		return (false);
	if (closing_b == ')' && opening_b != '(')
		return (false);
	return (true);
}

int	process_brackets(char *input, int index, char opening_b)
{
	while(input[index])
	{
		if(isOpeningB(input[index]))
		{
			index = process_brackets(input, index + 1, input[index]);
			if (index == -1)
				return (-1);
			index++;
		}
		else if(isClosingB(input[index]))
		{
			if(!isClosed(input[index], opening_b))
				return (-1);
			return (index);
		}
		else
			index++;
	}
	if (opening_b)
		return (-1);
	return (index);
}

/*
	cc -Wall -Wextra -Werror brackets_00.c
	./a.out "((((()))))"
	./a.out "(15 * ((42 + 1) / 2)[]())"
*/
int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	int i = 1;
	int ret = 0;
	while(argv[i])
	{
		ret = process_brackets(argv[i], 0, 0);
		if(ret == -1)
		{
			write(1, "Error\n", 6);
			break ;
		}
		i++;
	}
	if (ret != -1)
		write(1, "OK\n", 3);
	return (0);

}
