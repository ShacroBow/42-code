/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:25:56 by kmashkoo          #+#    #+#             */
/*   Updated: 2025/02/10 14:38:05 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_global
{
	int				i;
	unsigned char	byte;
}	t_global;

void	ft_putnbr(int n);
int		ft_atoi(const char *nptr);
void	ft_sigactionhandle(struct sigaction s_target);

#endif