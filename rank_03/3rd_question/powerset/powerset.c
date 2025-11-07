/*	I need to implement a recursive backtracking algorithm
*/

#include <stdlib.h>

void	process_input(int target, int *numbers, int n_numbers, int i, int j, int sum)
{
	int j = 1;
	while (i < n_numbers)
	{
		if (target == sum + ???)
		{

		}
		if (target == numbers[i] + numbers[j])
		{
			printf("%d %d\n", numbers[i], numbers[j]);
			return (process_input(target, numbers, n_numbers, i, j + 1, 0));
		}
		if (target < numbers[i] + numbers[j])
			return ();
		if (target > numbers[i] + numbers[j])
		{
			sum = numbers[i] + numbers[j]
		}
	}
}

int main(int argc, char **argv)
{
	int	target = atoi(argv[1]);
	int	numbers[argc - 2];
	int i = 0;
	while (i < argc - 2)
	{
		numbers[i] = atoi(argv[i + 2]);
		i++;
	}
	process_input(target, numbers, argc - 2, 0, 0, 0);
	return (0);
}
