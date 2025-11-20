#include <stdio.h>
#include <stdlib.h>

void	print_set(int *subset, int n_subset)
{
	if (n_subset == 0)
	{
		printf("\n");
		return ;
	}
	int i = 0;
	while (i < n_subset)
	{
		if (i == n_subset - 1)
			printf("%d\n", subset[i]);
		else
			printf("%d ", subset[i]);
		i++;
	}
}

void	backtrack(int target, int *set, int n_set, int *subset, int n_subset, int index, int sum)
{
	if (index == n_set)
	{
		if (target == sum)
			print_set(subset, n_subset);
		return ;
	}
	subset[n_subset] = set[index];
	backtrack(target, set, n_set, subset, n_subset + 1, index + 1, sum + set[index]);
	backtrack(target, set, n_set, subset, n_subset, index + 1, sum);
}

/*
	cc -Wall -Wextra -Werror powerset_00.c
*/
int	main(int argc, char **argv)
{
	if (argc < 3)
		return (1);
	int	set[argc - 2];
	int	subset[argc - 2];
	int i = 2;
	while (argv[i])
	{
		set[i - 2] = atoi(argv[i]);
		i++;
	}
	backtrack(atoi(argv[1]), set, argc - 2, subset, 0, 0, 0);
	return (0);
}
