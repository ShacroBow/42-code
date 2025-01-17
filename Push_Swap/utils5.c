
#include "pushswap.h"

int	ft_index(t_array *array)
{
	return (array->index);
}

int	ft_value(t_array *array)
{
	return (array->value);
}

t_array	*ft_next(t_array *array)
{
	return (array->next);
}

int	ft_arraysize(t_array *array)
{
	int		i;
	t_array	*tmp;

	i = 0;
	tmp = array;
	while (array)
	{
		tmp = tmp->next;
		i++;
		if (tmp->index == 0)
			return (i);
	}
	return (0);
}