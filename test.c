#include <stdio.h>

int		get_color(int x, int y)
{
	return((x * 3) + (y * 3 * 4));
}

int main()
{
	printf("HUY::%d\n", get_color(3, 1));
	return (0);
}