#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char *g_input;
int g_pos = 0;

int parse_expression();  // Forward declaration

int parse_factor()
{
	if (g_input[g_pos] == '(')
	{
		g_pos++;
		int result = parse_expression();

		if (g_input[g_pos] != ')')
		{
			if (g_input[g_pos] == '\0')
				printf("Unexpected end of input\n");
			else
				printf("Unexpected token '%c'\n", g_input[g_pos]);
			exit(1);
		}
		g_pos++;
		return result;
	}
	else if (isdigit(g_input[g_pos]))
	{
		int value = g_input[g_pos] - '0';
		g_pos++;
		return value;
	}
	else
	{
		if (g_input[g_pos] == '\0')
			printf("Unexpected end of input \n");
		else
			printf("Unexpected token '%c'\n", g_input[g_pos]);
		exit (1);
	}
}

int parse_term()
{
	int result = parse_factor();
	while (g_input[g_pos] == '*')
	{
		g_pos++;
		result *= parse_factor();
	}
	return result;
}

int parse_expression()
{
	int result = parse_term();
	while (g_input[g_pos] == '+')
	{
		g_pos++;
		result += parse_term();
	}
	return (result);
}

int main(int argc, char **argv) {
	if (argc != 2) return 1;
	g_input = argv[1];
	g_pos = 0;

	int result = parse_expression();

	// Check if we consumed everything
	if (g_input[g_pos] != '\0') {
		printf("Unexpected token '%c'\n", g_input[g_pos]);
		return 1;
	}

	printf("%d\n", result);
	return 0;
}
