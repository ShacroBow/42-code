/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:25:30 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/10/03 17:04:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(const char *string, ...);
int		ft_putchar(char x);
int		ft_putstring(char *x);
int		ft_itoa_signed(int x);
int		ft_uitoa_unsigned(unsigned int x);
char	*ft_uitoa(unsigned int n);
char	*ft_itohex(size_t n);
int		ft_itohex_low(unsigned int x);
int		ft_itohex_cap(unsigned int x);
int		ft_itohex_point(unsigned long int x);
int		ft_failcheck_printf(int k);

#endif