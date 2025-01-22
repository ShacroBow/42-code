/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:39:23 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/12/25 18:39:32 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	*ft_freelist(t_array *head, int i)
{
	int		j;
	t_array	*ptr;
	t_array	*tmp;

	if (i <= 0)
		return (NULL);
	j = 0;
	ptr = head;
	while (j < i)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
		j++;
	}
	return (NULL);
}

t_array	*ft_createlist(int len)
{
	int		i;
	t_array	*new_node;
	t_array	*head;
	t_array	*current;

	if (len <= 0)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_node = (t_array *)ft_calloc(1, sizeof(t_array));
		if (!new_node)
			return (ft_freelist(head, i));
		new_node->index = i;
		if (i == 0)
		{
			head = new_node;
			current = new_node;
		}
		current->next = new_node;
		current = new_node;
		i++;
	}
	current->next = head;
	return (head);
}

t_array	*ft_pointto(t_array *ptr, int index)
{
	int		i;
	t_array	*tmp;

	if (ptr == NULL)
		return (NULL);
	i = 0;
	tmp = ptr;
	while (i <= ARGS_MAX * 2)
	{
		tmp = tmp->next;
		if (index >= 0)
		{
			if (tmp->index == index)
				return (tmp);
		}
		else
		{
			if (tmp->next->index == 0)
				return (tmp);
		}
		i++;
	}
	return (NULL);
}


int	ft_correctindex(t_array *arrayhead)
{
	int		i;
	t_array	*tmp;

	if (arrayhead == NULL)
		return (-1);
	i = 0;
	tmp = arrayhead;
	while (i <= ARGS_MAX * 2)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
		if (tmp == arrayhead)
			return (i);
	}
	return (-1);
}

int	*ft_commandadd(int command, int **commands, int *len)
{
	if (command < 0 || command > 10)
		return (*commands);
	if (*commands == NULL || len == NULL || *len < 0)
		return (NULL);
	*commands = ft_realloc(*commands, *len - 1 , *len + 1, sizeof(int));
	if (*commands == NULL)
		return (NULL);
	(*len)++;
	(*commands)[(*len) - 1] = command;
	return (*commands);
}