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

void	ft_freearray(t_array **array)
{
	int		i;
	int		j;
	t_array	*ptr;
	t_array	*tmp;

	j = 0;
	if (*array == NULL)
		return ;
	tmp = ft_pointto(*array, -1);
	i = tmp->index + 1;
	ptr = ft_pointto(*array, 0);
	while (j < i)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
		j++;
	}
	*array = NULL;
}

t_array	*ft_createlist(int len)
{
	int		i;
	t_array	*new_node;
	t_array	*head;

	if (len <= 0)
		return (NULL);
	i = 0;
	head = NULL;
	while (i < len)
	{
		new_node = (t_array *)ft_calloc(1, sizeof(t_array));
		if (!new_node)
			return (ft_freearray(&head), NULL);
		new_node->next = new_node;
		
		ft_push(&new_node, &head, -9);
		i++;
	}
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

t_array	*ft_comadd(int comadd, t_array *commands)
{
	t_array *tmp;

	if (comadd < 0 || comadd > 10)
		return (commands);
	tmp = ft_createlist(1);
	if (!tmp)
		return (ft_freearray(&commands), NULL);
	tmp->value = comadd;
	if (commands == NULL)
		return (tmp);
	commands = ft_pointto(commands, 0);
	ft_push(&tmp, &commands, -9);
	return (commands);
}