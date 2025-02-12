/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:22:18 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/12 17:21:17 by kmashkoo         ###   ########.fr       */
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

static int	ft_mainhelperhelperhelper(int argc, char **argv)
{
	int	i;
	int	tmp;
	int	args;

	args = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_count_arguments(argv[i]) == 0)
			i++;
		if (argv[i] == NULL)
			return (args);
		tmp = ft_count_arguments(argv[i]);
		if (tmp == -1)
			return (-1);
		args += tmp;
		i++;
	}
	return (args);
}

int	*ft_mainhelper(int argc, char **argv, int *len)
{
	int	i;
	int	args;
	int	*array;

	i = 1;
	args = 0;
	array = NULL;
	if (argc > 1)
	{
		args = ft_mainhelperhelperhelper(argc, argv);
		*len = 0;
		array = ft_calloc(args + 1, sizeof(int));
		if (!array || args < 1)
			ft_exiterror(array);
		i = 1;
		while (i < argc)
		{
			while (argv[i] == NULL || ft_count_arguments(argv[i]) == 0)
				i++;
			if (*len == args)
				return (array);
			array = ft_parse_string(&(argv[i++]), array, len);
		}
	}
	return (array);
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
	a = NULL;
	buf = ft_mainhelper(argc, argv, &len);
	if (ft_checkdup(buf, len) || len > ARGS_MAX || !buf || argc < 2)
		ft_exiterror(buf);
	buf = ft_radixposition(buf, len);
	a = ft_createlist(len);
	if (!a)
		ft_exiterror(buf);
	a = ft_applyarray(a, buf, len);
	commands = ft_pushswap(&a, &b);
	if (!commands)
		ft_exiterror(buf);
	ft_commandprinter(commands);
	return (free(buf), ft_freearray(&a), 0);
}
