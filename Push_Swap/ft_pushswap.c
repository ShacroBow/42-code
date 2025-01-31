/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:51:23 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/01/15 16:51:24 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void ft_arrayprint(t_array *array)
{
	array = ft_pointto(array ,0);
	for (int i = 0; i < ft_arraysize(array); i++)
	{
	printf("%d ", array->value);
	array = array->next;
	}
	printf("\n");
}

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
	if (head > next)
		return (ft_swap(array, A));
	if (head < next && last > next)
		return (ft_rotate(array, A));
	if (last < next && head < last)
		return (ft_reverserotate(array, A));
	if (last < next && head > last && \
		(head + 1 == next && next + 1 == tmp->next->next->value))
		return (ft_reverserotate(array, A));
	if (ft_checkchunk(tmp, ft_index(ft_findhighlow(tmp, B)), \
		ft_index(ft_findhighlow(tmp, B)) - 1))
			return (ft_reverserotate(array, A));
	return (ft_rotate(array, A));
}

static int ft_searchfinished(t_array **arraya, int cutoff)
{
	t_array	*tmp;
	t_array	*last;

	tmp = ft_pointto(*arraya, 0);
	last = ft_pointto(*arraya, -1);
	if (tmp == NULL)
	{
		return 0;
	}
	
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

int ft_find_direction(t_array *array, int targetcutoff)
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
			break;
		rev++;
		tmp = tmp->next;
	}
	if (rev > mid)
		return (2);
	else if (rev < mid && rev > 0)
		return (1);
	return (0);
}


int ft_find_target(t_array *array, int target)
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
			break;
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
	int		i;
	int		peak;
	t_array	*head;

	i = 0;
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
	int		borth;
	int		chunk;
	int		peak;
	t_array	*head;

	i = 1;
	chunk = 0;
	*arya = ft_pointto(*arya, 0);
	peak = ft_value(ft_findhighlow(*arya, A));
	borth = (peak / n);
	while (i < n + 1)
	{
		chunk += borth;
		fflush(stdout);
		while ((*arya) && !ft_searchfinished(arya, chunk) && j < 500)
		{
			head = ft_pointto(*arya, 0);
			if ((head->value <= chunk))
			{
				j = 0;
				*com = ft_comadd(ft_push(arya, aryb, A), *com);
			}
			if (ft_find_direction(head, chunk) == 2)
				*com = ft_comadd(ft_reverserotate(*arya, A), *com);
			else if (ft_find_direction(head, chunk) == 1)
				*com = ft_comadd(ft_rotate(*arya, A), *com);
			j++;
		}
		// printf("j[%5d]head[%d]chunk[%d]dir[%d]\n", j, head->value, chunk, ft_find_direction(head, chunk));
		i++;
	}
	
	return (*com);
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
	
	if (ft_arraysize(*arraya) > 20 && !(ft_arraysize(*arraya) > 99 && ft_arraysize(*arraya) < 400))
	{
		if (ft_arraysize(*arraya) > 6 && ft_arraysize(*arraya) < 99)
			commands = ft_ogrechunk(arraya, arrayb, &commands, 6);
		else if (ft_arraysize(*arraya) > 99 && ft_arraysize(*arraya) < 400)
			commands = ft_ogrechunk(arraya, arrayb, &commands, 9);
		else if (ft_arraysize(*arraya) > 400)
			commands = ft_ogrechunk(arraya, arrayb, &commands, 9);
		

		while ((*arrayb))
			commands = ft_comadd(ft_push(arrayb, arraya, B), commands);


		if (ft_arraysize(*arraya) > 6 && ft_arraysize(*arraya) < 99)
			commands = ft_ogrechunk(arraya, arrayb, &commands, 6*5);
		else if (ft_arraysize(*arraya) > 99 && ft_arraysize(*arraya) < 400)
			commands = ft_ogrechunk(arraya, arrayb, &commands, 9*5);
		else if (ft_arraysize(*arraya) > 400)
			commands = ft_ogrechunk(arraya, arrayb, &commands, 10*5);
	
		while ((*arraya))
			commands = ft_comadd(ft_push(arraya, arrayb, A), commands);
		commands = ft_ogrebackchunk(arraya, arrayb, &commands);
	}
	else if (ft_arraysize(*arraya) > 99 && ft_arraysize(*arraya) < 400)
	{
		commands = ft_ogrechunk(arraya, arrayb, &commands, 8);
		while ((*arraya))
			commands = ft_comadd(ft_push(arraya, arrayb, A), commands);
		commands = ft_ogrebackchunk(arraya, arrayb, &commands);
	}

	


	commands = ft_sortswirl(arraya, arrayb, &commands);
	if (!commands)
		return (ft_freearray(arraya), ft_freearray(arrayb), NULL);
	return (ft_freearray(arraya), ft_freearray(arrayb), commands);
}