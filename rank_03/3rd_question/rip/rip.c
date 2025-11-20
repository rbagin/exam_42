#include <unistd.h>
#include <stdbool.h>

/*	rip
	(you have a string with parentheses (), and you need to check if all of them are balanced.
	if they are not balanced, you need to remove unbalanced parenthesies with whitespace
	and print all possible variation with balanced. "()())()" ---> 1. ()( )() 2. ( ())()

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
	
}
