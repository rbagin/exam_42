#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void	print_queens(int *board, int N)
{
	int i = 0;
	while (i < N)
	{
		if (i == N - 1)
		{
			printf("%d\n", board[i]);
			return ;
		}
		printf("%d ", board[i]);
		i++;
	}
	printf("\n");
}

int	abs(int x)
{
	if (x < 0)
		x = x * -1;
	return (x);
}

bool	isSafe(int *board, int x, int y)
{
	int i = 0;
	while (i < x)
	{
		if (board[i] == y || abs(i - x) == abs(board[i] - y))
			return (false);
		i++;
	}
	return (true);
}

void	solve_queens(int N, int *board, int x, int y)
{
	if (x >= N)
	{
		print_queens(board, N);
		return ;
	}
	if (y >= N)
		return ;
	if (isSafe(board, x, y))
	{
		board[x] = y;
		solve_queens(N, board, x + 1, 0);
		board[x] = -1;
		solve_queens(N, board, x, y + 1);
	}
	else
		solve_queens(N, board, x, y + 1);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	int N = atoi(argv[1]);
	if (N <= 3)
	{
		printf("\n");
		return (0);
	}
	int board[N];
	for (int i = 0; i < N; i++)
		board[i] = -1;
	solve_queens(N, board, 0, 0);
	return (0);
}
