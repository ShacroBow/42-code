/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:50:12 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/11 13:42:50 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_global
{
	int				i;
	unsigned char	byte;
	int				ln;
	int				count;
	char			*ptr;
}	t_global;

void	ft_putnbr(int n);
int		ft_atoi(const char *nptr);
void	ft_sigactionhandle(struct sigaction s_target);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
