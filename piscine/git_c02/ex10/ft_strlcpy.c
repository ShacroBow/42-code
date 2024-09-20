/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:46:04 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/20 15:04:07 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
	{
		return (i);
	}
	while (src[i + 1] != '\0' && (i < size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
	{
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
/* int	main(void)
{
	char str[] = "jghyhfdhfd";
	char dest[] = "AS56sDSdjgd";
	printf("%i\n", ft_strlcpy(dest,str, 10));
	printf("%s", dest);
}  */
