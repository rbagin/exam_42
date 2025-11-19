#include <stdio.h>
#include <stdlib.h>

void	backtrack(int target, int *set, int n_set, int index, int sum)
{

}

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (1);
	int	set[argc - 2];
	int i = 2;
	while (argv[i])
	{
		set[i - 2] = atoi(argv[i]);
		i++;
	}
	backtrack(atoi(argv[1]), set, i - 2, 0, 0);
	return (0);
}
