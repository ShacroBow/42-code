/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:51:23 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/01 14:41:39 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_sortsmall(t_array *array)
{
	t_array	*tmp;
	t_array	*end;
	int		head;
	int		next;
	int		last;

	tmp = ft_pointto(array, 0);
	end = ft_pointto(array, -1);
	array = ft_pointto(array, 0);
	next = tmp->next->value;
	head = tmp->value;
	last = end->value;
	if (ft_checkchunk(tmp, ft_index(ft_findhighlow(tmp, B)), \
		ft_index(ft_findhighlow(tmp, B)) - 1))
		return (ft_reverserotate(array, A));
	if (head > next)
		return (ft_swap(array, A));
	if (head < next && last > next)
		return (ft_rotate(array, A));
	if (last < next && head < last)
		return (ft_reverserotate(array, A));
	if (last < next && head > last && \
		(head + 1 == next && next + 1 == tmp->next->next->value))
		return (ft_reverserotate(array, A));
	return (ft_rotate(array, A));
}

int	ft_find_direction(t_array *array, int targetcutoff)
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
		if (tmp->value <= targetcutoff)
			break ;
		rev++;
		tmp = tmp->next;
	}
	if (rev > mid)
		return (2);
	else if (rev < mid && rev > 0)
		return (1);
	return (0);
}

t_array	*ft_pushswap(t_array **arraya, t_array **arrayb)
{
	t_array	*commands;

	commands = NULL;
	(*arraya) = ft_pointto((*arraya), 0);
	while (!ft_checksorted(*arraya, A) && ft_arraysize(*arraya) < 6)
		commands = ft_comadd(ft_sortsmall(*arraya), commands);
	if (ft_checksorted(*arraya, A) && ft_arraysize(commands) < 10)
		return (commands);
	commands = ft_backtrace(arraya, arrayb, commands, ft_arraysize(commands));
	ft_freearray(&commands);
	commands = ft_ogresize(arraya, arrayb, &commands, ft_arraysize(*arraya));
	commands = ft_sortswirl(arraya, arrayb, &commands);
	if (!commands)
		return (ft_freearray(arraya), ft_freearray(arrayb), NULL);
	return (ft_freearray(arraya), ft_freearray(arrayb), commands);
}
