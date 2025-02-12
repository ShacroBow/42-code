/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:51:48 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/12 16:28:11 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_array	*ft_findhighlow(t_array *array, int aorb)
{
	t_array	*tmp;
	int		target;

	tmp = array;
	target = ft_value(tmp);
	while (aorb == A)
	{
		if (target < tmp->value)
			target = tmp->value;
		tmp = tmp->next;
		if (target == tmp->value)
			return (tmp);
	}
	while (aorb == B)
	{
		if (target > tmp->value)
			target = tmp->value;
		tmp = tmp->next;
		if (target == tmp->value)
			return (tmp);
	}
	return (NULL);
}

int	ft_checkchunk(t_array *array, int startindex, int endindex)
{
	int		i;
	int		previousval;
	t_array	*tmp;

	i = 0;
	tmp = ft_pointto(array, startindex);
	while (tmp->index != endindex)
	{
		previousval = tmp->value;
		tmp = tmp->next;
		if (previousval > tmp->value)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_checkchunk_b(t_array *array, int startindex, int endindex)
{
	int		i;
	int		previousval;
	t_array	*tmp;

	i = 0;
	tmp = ft_pointto(array, startindex);
	while (tmp->index != endindex)
	{
		previousval = tmp->value;
		tmp = tmp->next;
		if (previousval < tmp->value)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_checksorted(t_array *array, int aorb)
{
	t_array	*tmp;

	tmp = ft_pointto(array, -1);
	if (aorb == A && array)
	{
		return (ft_checkchunk(array, 0, tmp->index));
	}
	else if (aorb == B && array)
	{
		return (ft_checkchunk_b(array, 0, tmp->index));
	}
	return (0);
}
