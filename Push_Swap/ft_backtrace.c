/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:48:08 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/01 14:48:23 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_2(t_array **arraya, t_array **arrayb, int command)
{
	if (command == 0)
		ft_swap(*arraya, A);
	if (command == 1)
		ft_swap(*arrayb, B);
	if (command == 2)
	{
		ft_swap(*arraya, A);
		ft_swap(*arrayb, B);
	}
}

static void	ft_3_5(t_array **arraya, t_array **arrayb, int command)
{
	if (command == 3)
		ft_reverserotate(*arraya, A);
	if (command == 4)
		ft_reverserotate(*arrayb, B);
	if (command == 5)
	{
		ft_reverserotate(*arraya, A);
		ft_reverserotate(*arrayb, B);
	}
}

static void	ft_6_8(t_array **arraya, t_array **arrayb, int command)
{
	if (command == 6)
		ft_rotate(*arraya, A);
	if (command == 7)
		ft_rotate(*arrayb, B);
	if (command == 8)
	{
		ft_rotate(*arraya, A);
		ft_rotate(*arrayb, B);
	}
}

static void	ft_9_10(t_array **arraya, t_array **arrayb, int command)
{
	if (command == 9)
		ft_push(arraya, arrayb, A);
	if (command == 10)
		ft_push(arrayb, arraya, B);
}

t_array	*ft_backtrace(t_array **arraya, t_array **arrayb, t_array *com, int n)
{
	int		i;
	t_array	*tmp;

	i = 0;
	tmp = ft_pointto(com, 0);
	while (i < n)
	{
		*arraya = ft_pointto(*arraya, 0);
		*arrayb = ft_pointto(*arrayb, 0);
		if (tmp->value <= 2)
			ft_2(arraya, arrayb, tmp->value);
		if (tmp->value >= 3 && tmp->value <= 5)
			ft_3_5(arraya, arrayb, tmp->value);
		if (tmp->value >= 6 && tmp->value <= 8)
			ft_6_8(arraya, arrayb, tmp->value);
		if (tmp->value >= 9 && tmp->value <= 10)
			ft_9_10(arraya, arrayb, tmp->value);
		tmp = tmp->next;
		i++;
	}
	tmp = ft_pointto(com, 0);
	return (tmp);
}
