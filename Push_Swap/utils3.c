/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:43:03 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/01/06 19:43:06 by kmashkoo         ###   ########.fr       */
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

t_array	*ft_applyarray(t_array *linkedlist, int *array, int len)
{
	int		i;
	t_array	*tmp;
	t_array	*last;

	if (linkedlist == NULL)
		return (NULL);
	i = 0;
	last = ft_pointto(linkedlist, -1);
	while (i < len)
	{
		tmp = ft_pointto(linkedlist, i);
		tmp->value = array[i];
		
		i++;
	}
	return (last->next);
}

int	ft_push(t_array **array, t_array **target, int aorb)
{
	int		i;
	t_array	*last;
	t_array	*head;
	t_array	*tmp;

	i = 0;
	last = ft_pointto(*array, -1);
	head = ft_pointto(*array, 0);
	last->next = head->next;
	ft_correctindex(last->next);
	if (head == head->next)
		*array = NULL;
	if (*target == NULL)
	{
		*target = head;
		(*target)->next = *target;
	}
	else
	{
		last = ft_pointto(*target, -1);
		tmp = last->next->next;
		last->next = head;
		head->next = tmp;
		ft_correctindex(last->next);
	}
	
	return (9 + aorb);
}