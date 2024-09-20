/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:57:09 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/09/19 12:11:19 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen_strtrim(const char *str)
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

static char	*ft_strnstr_strtrim(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	ptr = (char *)big;
	if (big[0] == '\0' || little[0] == '\0')
		return (ptr);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] != '\0' && big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return (ptr + i);
			++j;
		}
		++i;
	}
	return (0);
}

static char	*ft_supermalloc_strtrim(int k, int i, int j)
{
	char	*ptr;

	if (k == 3)
		ptr = (char *) malloc((i - (j * 2)) + 1);
	if (k == 2 || k == 1)
		ptr = (char *) malloc((i - j) + 1);
	else if (k < 1 || k > 3)
		return (0);
	return (ptr);
}

static char	*ft_strcpy_trim(const char *s1, int k, int i, int j)
{
	int		hel;
	char	*ptr;

	hel = 0;
	ptr = ft_supermalloc_strtrim(k, i, j);
	while (k == 3 && hel < (i - (j * 2)))
	{
		ptr[hel] = s1[hel + j];
		hel++;
	}
	while (k == 2 && hel < i - j)
	{
		ptr[hel] = s1[hel];
		hel++;
	}
	while (k == 1 && hel < i - j)
	{
		ptr[hel] = s1[hel + j];
		hel++;
	}
	ptr[hel] = '\0';
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;
	char	*strnstr_check;

	k = 0;
	if (s1 == 0 || set == 0)
		return (0);
	i = ft_strlen_strtrim(s1);
	j = ft_strlen_strtrim(set);
	strnstr_check = ft_strnstr_strtrim(s1, set, i);
	if (strnstr_check == s1)
	{
		k += 1;
	}
	strnstr_check = ft_strnstr_strtrim(s1 + j, set, i - j);
	if (strnstr_check == (s1 +(i - j)))
	{
		k += 2;
	}
	ptr = ft_strcpy_trim(s1, k, i, j);
	return (ptr);
}
/* #include <stdio.h>

int main()
{
	
	// char *string = "easypeasy.com";
	// char *set = ".com";
	// char *set2 = "easy";
	// char *string = "HelloHilHiHello";
	// char *set = "Hello";
	// char *set2 = "Hi";
	char *string = "xXDARKNESSXx";
	char *set = "x";
	char *set2 = "X";
	
	char *ptr;
	char *FREETEMP;
	printf("string untrimed: %s\n", string);

	ptr = ft_strtrim(string, set);
	printf("string trimed: %s\n", ptr);
	FREETEMP = ptr;
	ptr = ft_strtrim(ptr, set2);
	printf("string trimed2: %s\n", ptr);
	free(FREETEMP);
	free(ptr);

	return 0;
} */