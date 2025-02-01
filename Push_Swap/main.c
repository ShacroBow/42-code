/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:22:18 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/01 15:34:13 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_checkdup(int *array, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (array[i] == array[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*ft_mainhelper(int argc, char **argv, int *len)
{
	int	*buf;

	if (argc < 2)
		return (NULL);
	if (argc == 2)
		buf = ft_parse_string(argv[1], len);
	else
	{
		buf = ft_parse_arguments(argc, argv);
		*len = argc - 1;
	}
	return (buf);
}

int	main(int argc, char **argv)
{
	int		*buf;
	int		len;
	t_array	*commands;
	t_array	*a;
	t_array	*b;

	len = 0;
	b = NULL;
	buf = ft_mainhelper(argc, argv, &len);
	a = ft_createlist(len);
	if (ft_checkdup(buf, len) || len > ARGS_MAX || !buf || !a)
		ft_exiterror(buf);
	if (len == 1)
		return (0);
	buf = ft_radixposition(buf, len);
	a = ft_applyarray(a, buf, len);
	free(buf);
	commands = ft_pushswap(&a, &b);
	if (!commands)
		ft_exiterror(buf);
	ft_commandprinter(commands);
	ft_freearray(&commands);
	return (0);
}
