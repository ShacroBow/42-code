/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:11:54 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/01 15:43:12 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static long int	ft_turnit_helper(int *i, int *j, int *array, char *str)
{
	char		buf[1024];
	long int	actual;

	while ((ft_isdigit(str[*i]) || \
			(str[*i] == '-' || str[*i] == '+')) && *j < 1023)
	{
		buf[*j] = str[*i];
		(*j)++;
		(*i)++;
	}
	buf[*j] = '\0';
	actual = ft_atol(buf, j);
	if ((actual > 2147483647 || actual < -2147483648) || \
		(*j > 11) || !ft_proper_input(buf))
		ft_exiterror(array);
	return (actual);
}

static int	*ft_turnit(char *str)
{
	int			i;
	int			j;
	int			k;
	long int	actual;
	int			*array;

	i = 0;
	k = 0;
	array = ft_calloc(ft_count_arguments(str) + 1, sizeof(int));
	if (array == NULL)
		ft_exiterror(NULL);
	while (str[i])
	{
		j = 0;
		actual = ft_turnit_helper(&i, &j, array, str);
		array[k] = actual;
		k++;
		while (ft_isspace(str[i]))
			i++;
	}
	return (array);
}

int	*ft_parse_string(char *argv, int *len)
{
	int		i;
	int		j;
	int		*array;

	i = 0;
	j = 0;
	*len = 0;
	if (argv == NULL)
		ft_exiterror(NULL);
	argv = ft_skipwhitespace(argv);
	*len = ft_strlen(argv);
	while (ft_isdigit(argv[j]) || \
			(argv[j] == '-' || argv[j] == '+') || argv[j] == ' ')
		j++;
	if ((*len - j) != 0)
		ft_exiterror(NULL);
	array = ft_turnit(argv);
	*len = ft_count_arguments(argv);
	return (array);
}
