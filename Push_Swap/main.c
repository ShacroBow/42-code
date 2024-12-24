/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:22:18 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/12/20 20:22:08 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int ft_checkdup(int *array, int len)
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

int main(int argc, char **argv)
{
	int	*buf;
	int	len;

	len = 0;
	if (argc < 2)
		return 0;
	if (argc == 2)
		buf = ft_parse_string(argv[1], &len);
	else
	{
		buf = ft_parse_arguments(argc, argv);
		len = argc - 1;
	}
	if (ft_checkdup(buf, len))
		ft_exiterror(buf);
	buf = ft_radixposition(buf, len);
	ft_pushswap(buf, len);
	
	for (int i = 0; i < len; i++)
	{
		printf("%d ", buf[i]);
	}
	printf("\n");
	return (0);
}