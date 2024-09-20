/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:05:37 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/09/14 14:28:27 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen_strjoin(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

static char	*ft_strjoincalc_strjoin(char *ptr, const char *s1, const char *s2)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = ft_strlen_strjoin(s1);
	k = ft_strlen_strjoin(s2);
	while (j != 0 && i < j)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (k != 0 && i < (k + j))
	{
		ptr[i] = s2[i - j];
		i++;
	}
	if (j + k != 0)
	{
		ptr[i] = '\0';
		return (ptr);
	}
	free(ptr);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		j;
	int		k;
	char	*ptr;

	if (s1 == 0 || s2 == 0)
		return (0);
	j = ft_strlen_strjoin(s1);
	k = ft_strlen_strjoin(s2);
	ptr = (char *)malloc(k + j + 1);
	if (!ptr)
		return (0);
	ptr = ft_strjoincalc_strjoin(ptr, s1, s2);
	return (ptr);
}
/* #include <stdio.h>

int	main(void)
{
	char string[50] = "Fourty ";
	char string2[50] = "two";
	char *ptr;
	
	ptr = ft_strjoin(string, string2);
	printf("my strjoining: %s\n", ptr);
	free(ptr);
	return 0;
} */