/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:51:17 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/01/15 16:51:18 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_commandprinter(t_array *commands)
{
	int		i;
	int		j;
	t_array	*tmp;

	i = 0;
	j = ft_arraysize(commands);
	tmp = ft_pointto(commands, -1);
	while (i < j)
	{
		// printf("ft_print logic code[%d]\n", tmp->value);
		ft_print(tmp->value);
		write(1, "\n", 1);
		i++;
		tmp = ft_pointto(tmp, tmp->index - 1);
	}
	// printf("compute[%d]\n", ft_arraysize(commands));
}

static void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_print(int command)
{
	if (command == 0)
		ft_putstr("sa");
	if (command == 1)
		ft_putstr("sb");
	if (command == 2)
		ft_putstr("ss");
	if (command == 3)
		ft_putstr("ra");
	if (command == 4)
		ft_putstr("rb");
	if (command == 5)
		ft_putstr("rr");
	if (command == 6)
		ft_putstr("rra");
	if (command == 7)
		ft_putstr("rrb");
	if (command == 8)
		ft_putstr("rrr");
	if (command == 9)
		ft_putstr("pb");
	if (command == 10)
		ft_putstr("pa");
}