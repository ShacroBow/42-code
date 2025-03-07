/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:51:17 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/01 21:48:45 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_commandprinter(t_array *commands)
{
	int		i;
	int		j;
	t_array	*tmp;

	i = 0;
	if (commands->value > ARGS_MAX + 1)
		return ;
	j = ft_arraysize(commands);
	tmp = ft_pointto(commands, -1);
	while (i < j)
	{
		ft_print(tmp->value);
		write(1, "\n", 1);
		i++;
		tmp = ft_pointto(tmp, tmp->index - 1);
	}
	ft_freearray(&commands);
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
