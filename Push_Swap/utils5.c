/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:02:42 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/01 21:35:29 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_index(t_array *array)
{
	return (array->index);
}

int	ft_value(t_array *array)
{
	return (array->value);
}

// t_array	*ft_next(t_array *array)
// {
// 	return (array->next);
// }

int	ft_arraysize(t_array *array)
{
	t_array	*tmp;

	if (array == NULL)
		return (0);
	tmp = ft_pointto(array, -1);
	return (tmp->index + 1);
}

t_array	*ft_applyarray(t_array *linkedlist, int *array, int len)
{
	int		i;
	t_array	*tmp;
	t_array	*last;

	if (linkedlist == NULL)
		return (NULL);
	i = 0;
	last = ft_pointto(linkedlist, -1);
	while (i < len)
	{
		tmp = ft_pointto(linkedlist, i);
		tmp->value = array[i];
		i++;
	}
	return (last->next);
}
