#include <unistd.h>
#include <stdbool.h>

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

int	validate_brackets(char *input, int index, char opening_b)
{
	while(input[index])
	{
		if (isOpeningBracket(input[index]))
		{
			index = validate_brackets(input, input[index], index + 1);
			if (index == -1)
				return (-1);
		}
		else if(isClosingBracket(input[index]))
		{
			if (isClosed(input[index], opening_b))
				return (0);
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

void	balance_brackets(char *output, char *input, bool *brackets, int index)
{
	while(input[index])
	{
		if 
	}
}
/*	rip
	(you have a string with parentheses (), and you need to check if all of them are balanced.
	if they are not balanced, you need to remove unbalanced parenthesies with whitespace
	and print all possible variation with balanced.
	./a.out "()())()":
			()( )()
			( ())()

	Aproach:
	1. First, identify which parentheses are unbalanced (mark invalid positions)
	2. Use backtracking to try different combinations of removing parentheses
	3. For each combination, check if it's balanced (using your brackets logic!)
	4. Keep track of all valid combinations with the same minimum number of removals
	5. Print all unique valid results
	*/
int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int	strlen = 0;
	while (argv[1][strlen])
		strlen++;
	bool	brackets[strlen];
	for (int i = 0; i < strlen; i++)
		brackets[i] = true;
	char	balanced_output[strlen + 1];
	balance_brackets(balanced_output, argv[1], brackets, 0);
	validate_brackets(balanced_output, 0, 0);
}
