/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:49:19 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/09/11 18:59:22 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*ptr;
	char	*ptr2;

	i = 0;
	ptr = (char *)s1;
	ptr2 = (char *)s2;
	while (ptr[i + 1] != '\0' && ptr2[i + 1] != '\0' && i + 1 < n)
	{
		++i;
	}
	return (ptr[i] - ptr2[i]);
}
/* 
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char str1[] = "Hello";
	char str2[] = "Hell0";

	int result = ft_strncmp(str1, str2, 7);
	printf("The strings is:%d.\n", result);


	result = strncmp(str1, str2, 7);
	printf("The original strings is:%d.\n", result);

	return 0;
} */