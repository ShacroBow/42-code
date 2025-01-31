
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
	t_array	*tmp;

	if (array == NULL)
		return (0);
	tmp = ft_pointto(array, -1);
	return (tmp->index + 1);
}
