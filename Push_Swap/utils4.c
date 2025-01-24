/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:51:48 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/01/15 16:51:52 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_checkchunk(t_array *array, int startindex, int endindex)
{
	int		i;
	int		previousval;
	t_array	*tmp;

	tmp = ft_pointto(array, startindex);
	i = 0;
	while (tmp->index != endindex)
	{
		previousval = tmp->value;
		tmp = tmp->next;
		if (previousval > tmp->value)
			return (0);
	}
	return (1);
}

int	ft_checksorted(t_array *array)
{
	t_array *tmp;

	tmp =  ft_pointto(array, -1);
	return (ft_checkchunk(array, 0, tmp->index));
}

static int	ft_compresscommands_helper(int commands, int previousval)
{
	if ((previousval == 1 || previousval == 4 || previousval == 7) && (previousval - 1) == commands)
	{
		return (previousval + 1);
	}
	if ((previousval == 0 || previousval == 3 || previousval == 6) && (previousval + 1) == commands)
	{
		return (previousval + 2);
	}
	return (-1);
}

int	*ft_compresscommands(int *commands, int *len)
{
	int	i;
	int	j;
	int	previousval;
	int	*tmp;

	i = 0;
	j = 0;
	while (i < *len)
	{
		previousval = commands[i];
		i++;
		if ((previousval + 1) == commands[i] || (previousval - 1) == commands[i])
		{
			tmp = ft_comadd(ft_compresscommands_helper(commands[i], previousval), &tmp, &j);
			i++;
		}
		else
			tmp = ft_comadd(commands[i], &tmp, &j);
	}
	*len = j;
	return (tmp);
}

t_array *ft_findhighlow(t_array *array, int aorb)
{
	t_array	*tmp;
	int		target;

	tmp = array;
	target = tmp->value;
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
	return NULL;
}//A means you look for max. B means you look for min