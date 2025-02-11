/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:43:03 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/11 19:16:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_swap(t_array *array, int aorb)
{
	int		tmp;
	t_array	*next;
	t_array	*head;

	tmp = 0;
	head = ft_pointto(array, 0);
	next = head->next;
	tmp = head->value;
	head->value = next->value;
	next->value = tmp;
	ft_correctindex(head);
	return (0 + aorb);
}

int	ft_rotate(t_array *array, int aorb)
{
	t_array	*head;

	head = ft_pointto(array, 0);
	ft_correctindex(head->next);
	return (3 + aorb);
}

int	ft_reverserotate(t_array *array, int aorb)
{
	t_array	*last;

	last = ft_pointto(array, -1);
	ft_correctindex(last);
	return (6 + aorb);
}

static void	ft_push_helper(t_array **array)
{
	t_array	*last;
	t_array	*head;

	last = ft_pointto(*array, -1);
	head = ft_pointto(*array, 0);
	if (head == head->next)
		*array = NULL;
	else if (*array != NULL && head->next == last)
	{
		head->next = head;
		last->next = last;
		*array = last;
		ft_correctindex(*array);
	}
	else
	{
		last->next = head->next;
		*array = last->next;
		ft_correctindex(*array);
	}
}

int	ft_push(t_array **array, t_array **target, int aorb)
{
	t_array	*head;

	head = ft_pointto(*array, 0);
	ft_push_helper(array);
	if (*target == NULL)
	{
		(*target) = head;
		(*target)->next = (*target);
	}
	else if (target)
	{
		(*target) = ft_pointto(*target, -1);
		head->next = (*target)->next;
		(*target)->next = head;
		ft_correctindex(head);
		(*target) = head;
	}
	return (9 + aorb);
}
