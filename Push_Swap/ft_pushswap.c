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

int	ft_sort3(t_array *array, int aorb)
{
	t_array	*target;

	array = ft_pointto(array, 0);
	target = ft_findhighlow(array, aorb);
	if (array->value == target->value)
		return (ft_rotate(array, aorb));
	if (array->next->value == target->value)
		return (ft_reverserotate(array, aorb));
	if (array->value > array->next->value)
		return (ft_swap(array, aorb));
	return (-1);
}
int	ft_cal_sorta(t_array **arraya, t_array **arrayb, int peak)
{
	t_array	*tmp;
	t_array	*tmp2;
	int		pushed_off;
	
	tmp = ft_pointto(*arraya, 0);
	tmp2 = ft_pointto(*arraya, -1);
	if (ft_checksorted(tmp))
		return (-1);
	if (!ft_peakfinished(arraya, peak) && tmp->value < (peak / 2))
		return (ft_push(arraya, arrayb, A));
	if (tmp->value > tmp->next->value)
		return (ft_swap(*arraya, A));
	if (tmp->value < tmp2->value)
		return (ft_reverserotate(*arraya, A));
	return (ft_rotate(*arraya, A));
}

int	ft_cal_sortb(t_array **arraya, t_array **arrayb, int peak)
{
	t_array	*tmp;
	t_array	*tmp2;
	int		pushed_off;
	
	tmp = ft_pointto(*arrayb, 0);
	tmp2 = ft_pointto(*arrayb, -1);
	if (ft_checksorted(tmp))
		return (-1);
	if (!ft_peakfinished(arraya, peak))
		return (-1);
	if (tmp->value > tmp->next->value)
		return (ft_swap(*arrayb, B));
	if (tmp->value < tmp2->value)
		return (ft_reverserotate(*arrayb, B));
	return (ft_rotate(*arrayb, B));
}

int ft_peakfinished(t_array **arraya, int peak)
{
	while (1)
	{
		
	}
	return (100000000000000000000000)
}


int	*ft_sortsmall(t_array **arraya, t_array **arrayb, int *commands, int *len)
{
	t_array	*target;
	t_array	*head;
	t_array	*last;
	int		peak;

	if (ft_arraysize(*arraya) == 3 && *arrayb == NULL)
		ft_sort3(*arraya, A);
	head = ft_pointto(array, 0);
	last = ft_pointto(array, -1);
	peak = ft_value(ft_findhighlow(array, A));
	while (1)
	{
		if (!commands)
			return (NULL);
		ft_commandadd(ft_cal_sorta(araryb, arrayb, peak), commands, len);
		ft_commandadd(ft_cal_sortb(araryb, arrayb, peak), commands, len);
		if (ft_checksorted(*arraya) && *arrayb = NULL)
			break;
	}
	return (commands);
}

void ft_pushswap(int *array, int len)
{
	int		i;
	int		comlen;
	int		*commands;
	t_array	*a;
	t_array	*b;

	i = 0;
	commands = NULL;
	a = ft_applyarray(ft_createlist(len), array, len);
	if (!a)
		return ;
	b = NULL;
	while (1)
	{
		i++;
		commands = ft_realloc(commands, i - 1 , i + 1, sizeof(int));
		if (!commands)
			return (ft_exit_pushswap(a), ft_exit_pushswap(b));
		commands[i - 1] = ft_sort3(a, A);
		if (ft_checksorted(a))
		{
			break;
		}
	}
	comlen = 0;
	commands = ft_compresscommands(commands, &i);
	if (!commands)
			return (ft_exit_pushswap(a), ft_exit_pushswap(b));
	ft_commandprinter(commands, i);
	a = ft_pointto(a, 0);
	while (1)
	{
		// printf("arrary[%d]\n", a->value);
		a = a->next;
		if (a->index == 0)
			break;
	}
	free(commands);
	ft_exit_pushswap(a);
	ft_exit_pushswap(b);
}

void	ft_exit_pushswap(t_array *array)
{
	int		i;
	int		j;
	t_array	*ptr;
	t_array	*tmp;

	if (array == NULL)
		return ;
	j = 0;
	tmp = ft_pointto(array, -1);
	i = tmp->index + 1;
	ptr = ft_pointto(array, 0);
	while (j < i)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
		j++;
	}
}