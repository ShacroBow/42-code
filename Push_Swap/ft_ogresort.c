/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ogresort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:40:33 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/11 19:18:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_searchfinished(t_array **arraya, int cutoff)
{
	t_array	*tmp;
	t_array	*last;

	tmp = ft_pointto(*arraya, 0);
	last = ft_pointto(*arraya, -1);
	if (tmp == NULL)
		return (0);
	while (1)
	{
		if (tmp->value <= cutoff)
			return (0);
		if (tmp->index == last->index)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_array	*ft_ogresize(t_array **arraya, t_array **arrayb, t_array **com, int n)
{
	if (n < 20)
		return (*com);
	if (n > 99 && !(n > 99 && n < 400))
	{
		if (n > 99 && n < 400)
			*com = ft_ogrechunk(arraya, arrayb, com, 6);
		else if (n > 400)
			*com = ft_ogrechunk(arraya, arrayb, com, 5);
		while ((*arrayb))
			*com = ft_comadd(ft_push(arrayb, arraya, B), *com);
		if (n > 99 && n < 400)
			*com = ft_ogrechunk(arraya, arrayb, com, 6 * 2);
		else if (n > 400)
			*com = ft_ogrechunk(arraya, arrayb, com, 10 * 2);
	}
	else if (n > 6 && n <= 99)
		*com = ft_ogrechunk(arraya, arrayb, com, 4);
	else if (n > 99 && n < 400)
		*com = ft_ogrechunk(arraya, arrayb, com, 5);
	while ((*arraya))
		*com = ft_comadd(ft_push(arraya, arrayb, A), *com);
	*com = ft_ogrebackchunk(arraya, arrayb, com);
	return (*com);
}

int	ft_find_target(t_array *array, int target)
{
	int		rev;
	int		mid;
	t_array	*tmp;
	t_array	*last;

	rev = 0;
	tmp = ft_pointto(array, 0);
	last = ft_pointto(array, -1);
	mid = ((last->index) / 2);
	while (tmp->index != last->index)
	{
		if (tmp->value == target)
			break ;
		rev++;
		tmp = tmp->next;
	}
	tmp = tmp->next;
	if (tmp->value == target)
		rev++;
	if (rev >= mid)
		return (2);
	else if (rev < mid && rev > 0)
		return (1);
	return (0);
}

t_array	*ft_ogrebackchunk(t_array **arya, t_array **aryb, t_array **com)
{
	int		peak;
	t_array	*head;

	*aryb = ft_pointto(*aryb, 0);
	while ((*aryb) != NULL)
	{
		head = ft_pointto(*aryb, 0);
		peak = ft_value(ft_findhighlow(*aryb, A));
		if (head->value == peak)
			*com = ft_comadd(ft_push(aryb, arya, B), *com);
		if (ft_find_target(head, peak) == 2)
			*com = ft_comadd(ft_reverserotate(*aryb, B), *com);
		else if (ft_find_target(head, peak) == 1)
			*com = ft_comadd(ft_rotate(*aryb, B), *com);
	}
	return (*com);
}

t_array	*ft_ogrechunk(t_array **arya, t_array **aryb, t_array **com, int n)
{
	int		i;
	int		j;
	int		fraction;
	int		chunk;
	t_array	*head;

	i = 1;
	chunk = 0;
	fraction = (ft_value(ft_findhighlow(*arya, A)) / n);
	while (i < n + 1)
	{
		chunk += fraction;
		while ((*arya) && !ft_searchfinished(arya, chunk) && ++j < 500)
		{
			head = ft_pointto(*arya, 0);
			if ((head->value <= chunk))
				*com = ft_comadd(ft_push(arya, aryb, A + (j = 0)), *com);
			if (ft_find_direction(head, chunk) == 2)
				*com = ft_comadd(ft_reverserotate(*arya, A), *com);
			else if (ft_find_direction(head, chunk) == 1)
				*com = ft_comadd(ft_rotate(*arya, A), *com);
		}
		i++;
	}
	return (*com);
}
