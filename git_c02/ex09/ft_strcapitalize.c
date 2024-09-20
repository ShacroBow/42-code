/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:16:37 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/06/20 15:04:13 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (str[0] >= 97 && str[0] <= 122)
	{
		str[i] = str[i] - 32;
	}
	i++;
	while (str[i] != '\0')
	{
		if ((str[i - 1] == ' ' || str[i - 1] == '+')
			&& (str[i] >= 97 && str[i] <= 122))
		{
			str[i] = str[i] - 32;
		}
		else if (!(str[i - 1] == ' ' || str[i - 1] == '+')
			&& (str[i] >= 65 && str[i] <= 90))
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

/* int	main(void)
{
	char hel[]="salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char hel2[] = "hello my friend.";
	char hel3[] = "giga spam of hell. I am saying very much words.";

	printf("%s\n", ft_strcapitalize(hel));
	printf("%s\n", ft_strcapitalize(hel2));
	printf("%s\n", ft_strcapitalize(hel3));
}  */