/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:11:54 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/11 19:16:20 by codespace        ###   ########.fr       */
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

static int	*ft_turnit(char *str, int *array, int *len)
{
	int			i;
	int			j;
	long int	actual;

	i = 0;
	if (array == NULL)
		ft_exiterror(NULL);
	while (str[i])
	{
		j = 0;
		actual = ft_turnit_helper(&i, &j, array, str);
		array[(*len)] = actual;
		(*len)++;
		while (ft_isspace(str[i]))
			i++;
	}
	return (array);
}

int	*ft_parse_string(char **str, int *array, int *len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	(*str) = ft_skipwhitespace((*str));
	while (ft_isdigit((*str)[j]) || \
			((*str)[j] == '-' || (*str)[j] == '+') || (*str)[j] == ' ')
		j++;
	if (!(ft_isdigit((*str)[j]) || ((*str)[j] == '-' || (*str)[j] == '+') || \
			(*str)[j] == ' ') && (*str)[j] != '\0')
		ft_exiterror(NULL);
	array = ft_turnit((*str), array, len);
	while (ft_isdigit((*str)[i]) || ((*str)[i] == '-' || (*str)[i] == '+'))
		(*str)++;
	return (array);
}
