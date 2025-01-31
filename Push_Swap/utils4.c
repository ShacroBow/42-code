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
}//A means you look for max. B means you look for min. you can also look for specific value
 
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
	t_array *tmp;
	
	tmp =  ft_pointto(array, -1);
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

// // t_array	*ft_orient_sort(t_array **arraya, t_array **arrayb)
// // {
// // 	int		i;
// // 	int		previousval;
// // 	t_array	*tmp;
// // 	t_array	*last;

// // 	tmp = ft_pointto(array, 0);
// // 	last = ft_pointto(array, -1);
// // 	i = 0;
// // 	while (1)
// // 	{
// // 			return (0);
// // 	}
// // }

// static int	ft_compresscommands_helper(int commands, int previousval)
// {
// 	if ((previousval == 1 || previousval == 4 || previousval == 7) && (previousval - 1) == commands)
// 	{
// 		return (previousval + 1);
// 	}
// 	if ((previousval == 0 || previousval == 3 || previousval == 6) && (previousval + 1) == commands)
// 	{
// 		return (previousval + 2);
// 	}
// 	return (-1);
// }

// int	*ft_compresscommands(int *commands, int *len)
// {
// 	int	i;
// 	int	j;
// 	int	previousval;
// 	int	*tmp;

// 	i = 0;
// 	j = 0;
// 	while (i < *len)
// 	{
// 		previousval = commands[i];
// 		i++;
// 		if ((previousval + 1) == commands[i] || (previousval - 1) == commands[i])
// 		{
// 			tmp = ft_comadd(ft_compresscommands_helper(commands[i], previousval), &tmp, &j);
// 			i++;
// 		}
// 		else
// 			tmp = ft_comadd(commands[i], &tmp, &j);
// 	}
// 	*len = j;
// 	return (tmp);
// }
