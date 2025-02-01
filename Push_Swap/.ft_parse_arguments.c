/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 06:27:27 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/01 19:57:53 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_islegal(char *str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (ft_isdigit(str[j]) || (str[j] == '-' || \
			str[j] == '+') || str[j] == ' ')
		j++;
	str = ft_proper_input(str);
	if ((len - j) != 0 || !str)
		return (0);
	return (j);
}

static int	*ft_arguments_helper(int i, int j, char **argv, int *array)
{
	int			legal;
	long int	actual;
	char		buf[1024];

	while (argv[i + 1][j] && j < 1023)
	{
		buf[j] = argv[i + 1][j];
		j++;
	}
	buf[j] = '\0';
	legal = ft_islegal(buf);
	actual = ft_atol(buf, &j);
	if (!legal || (actual > 2147483647 || actual < -2147483648) || \
		(j > 11) || !ft_proper_input(buf))
		ft_exiterror(array);
	array[i] = (int)actual;
	return (array);
}

int	*ft_parse_arguments(int argc, char **argv)
{
	int			i;
	int			j;
	int			*array;

	i = 0;
	array = ft_calloc(argc + 1, sizeof(int));
	if (!array)
		ft_exiterror(NULL);
	while (i < (argc - 1))
	{
		j = 0;
		array = ft_arguments_helper(i, j, argv, array);
		i++;
	}
	return (array);
}
