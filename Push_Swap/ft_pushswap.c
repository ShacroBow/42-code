#include "pushswap.h"

void ft_pushswap(int *array, int len)
{
	int	i;
	int	*arrayb;

	i = 0;
	arrayb = ft_calloc(len+1, sizeof(int));
	if (!arrayb)
		ft_exiterror(array);
	while (1)
	{
		if (array[0] > array[len])
		{
			ft_print(3);
			
		}
	}
	
	arrayb = ft_realloc(arrayb, len+1);
	free(arrayb);
	free(array);
	exit(0);
}