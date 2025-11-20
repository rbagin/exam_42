#include <stdio.h>
/*helper: check if an opening and closing bracket match
stack = array used as a stack for opened brackets
top  = index of top element in stack (-1 means empty)
*/

int	is_matching(char open, char closed)
{
	if (open == '(' && closed == ')')
		return (1);
	if (open == '{' && closed == '}')
		return (1);
	if (open == '[' && closed == ']')
		return (1);
	return (0);
}

int	check_br(const char *str, int i, char *stack, int top)
{
	char	c;

	c = str[i];
	if (c == '\0')
		return (top == -1);
	if (c == '(' || c == '[' || c == '{')
	{
		stack[++top] = c;
		return (check_br(str, i + 1, stack, top));
	}
	if (c == ')' || c == ']' || c == '}')
	{
		if (top < 0 || !is_matching(stack[top], c))
			return (0);
		top--;
		return (check_br(str, i + 1, stack, top));
	}
	return (check_br(str, i + i, stack, top));
}

int	main(int argc, char **argv)
{
	char	stack[1024];

	if (argc != 2)
		return (1);
	if (check_br(argv[1], 0, stack, -1))
		printf("ok\n");
	else
		printf("not\n");
	return (0);
}
