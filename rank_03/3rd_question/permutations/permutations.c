#include <unistd.h>
#include <stdbool.h>
#include <string.h>


void	print_output(char *output, int len)
{
	write(1, output, len);
	write(1, "\n", 1);
}

void	print_permutations(char *input, int i_len, char *output, int o_len , int index, bool *used)
{
	if(index == i_len)
	{
		print_output(output, i_len);
		return ;
	}
	for (int i = 0; i < i_len; i++)
	{
		if (used[i] == false)
		{
			output[index] = input[i];
			used[i] = true;
			print_permutations(input, i_len, output, o_len + 1, index + 1, used);
			used[i] = false;
		}
	}
}

/*	(you have a string with characters, and you need to print all permutations for
	that string (abc --> acb, cba, cab, bac etc)*/
int	main(int argc, char **argv)
{
	if (argc > 2)
		return (1);
	int len = strlen(argv[1]);
	char output[len + 1];
	output[len] = '\0';
	bool used[len];
	for (int i = 0; i < len; i++)
		used[i] = false;
	print_permutations(argv[1],len, output, 0, 0, used);
	return (0);
}
