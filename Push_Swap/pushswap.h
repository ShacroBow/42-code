/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:22:15 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/12/20 19:36:25 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

void	ft_pushswap(int *array, int len);
void	ft_print(int command);
int		*ft_radixposition(int *buf, int len);
int		*ft_parse_arguments(int argc, char **argv);
int		*ft_parse_string (char *argv, int *len);
long	ft_atol(const char *nptr, int *len);
char	*ft_skipwhitespace(char *str);
char	*ft_proper_input(char *str);
int		ft_count_arguments(char *str);
void	ft_exiterror(void *str);

# endif