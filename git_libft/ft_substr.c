/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:05:37 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/09/14 14:22:49 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	ptr = (char *)malloc(1 * len + 1);
	if (!ptr)
		return (0);
	while (i < len && s[start + i] != '\0' && ptr != 0)
	{
		ptr[i] = s[start + i];
		i++;
	}
	if (i == len && len != 0)
	{
		ptr[i] = '\0';
		return (ptr);
	}
	free(ptr);
	return (0);
}
/* #include <stdio.h>

int	main(void)
{
	char string[50] = "Hello this is the string that will be subbed";
	char *ptr;
	
	ptr = ft_substr(string, 3, 41);
	printf("my substring: %s\n", ptr);
	free(ptr);
	return 0;
} */