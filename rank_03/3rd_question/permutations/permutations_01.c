#include <unistd.h>
#include <stdbool.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}

void	print_output(char *str, int strlen)
{
		write(1, str, strlen);
		write(1, "\n", 1);
}

void	print_permutations(char *input, int i_len, char *output, int o_len, int index, bool *used)
{
	if (index == i_len)
	{
		print_output(output, o_len);
		return ;
	}
	for (int i = 0; i < i_len; i++)
	{
		if (used[i] == false)
		{
			used[i] = true;
			output[index] = input[i];
			print_permutations(input, i_len, output, o_len + 1, index + 1, used);
			used[i] = false;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int	len = ft_strlen(argv[1]);
	char	output[len + 1];
	output[len] = '\0';
	bool	used[len];
	for (int i = 0; i < len; i++)
		used[i] = false;
	print_permutations(argv[1], len, output, 0, 0, used);
	return (0);
}
