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
	while (comlen < i)
	{
		ft_print(commands[comlen]);
		write(1, "\n", 1);
		comlen++;
	}
	a = ft_pointto(a, 0);
	while (1)
	{
		printf("arrary[%d]\n", a->value);
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