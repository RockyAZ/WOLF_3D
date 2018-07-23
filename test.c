#include <stdlib.h>
#include <stdio.h>
int main()
{
	int **c;
	int i;
	int j;

	i = 0;
	j = 0;
	c = (int**)malloc(sizeof(int*) * 3);
	while (i < 3)
	{
		c[i] = (int*)malloc(sizeof(int) * 3);
		j = 0;
		while (j < 3)
		{
//			c[i][j] = (int)malloc(sizeof(int));
			c[i][j] = 5;
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			printf("%d  ", c[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
