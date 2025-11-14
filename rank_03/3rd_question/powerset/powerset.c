/*	I need to implement a recursive backtracking algorithm
*/

#include <stdlib.h>
#include <stdio.h>

void	print_subset(int *subset, int n_subset)
{
	int i = 0;
	while (i < n_subset)
	{
		if (i > 0)
			printf(" ");
		printf("%d", subset[i]);
		i++;
	}
	printf("\n");
}

void	backtrack(int target, int *set, int n_set, int index,int result, int *subset, int n_subset)
{
	if (index == n_set)
	{
		if (result == target)
		{
			print_subset(subset, n_subset);
		}
		return ;
	}
	subset[n_subset] = set[index];
	backtrack(target, set, n_set,
				(index + 1),
				result + set[index],
				subset,
				n_subset + 1);
	backtrack(target, set, n_set,
				index + 1,
				result,
				subset,
				n_subset);
}

int main(int argc, char **argv)
{
	int	target = atoi(argv[1]);
	int	numbers[argc - 2];
	int	subset[argc - 2];
	int i = 0;
	while (i < argc - 2)
	{
		numbers[i] = atoi(argv[i + 2]);
		i++;
	}
	backtrack(target, numbers, argc - 2, 0, 0, subset, 0);
	return (0);
}
