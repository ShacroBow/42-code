/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashkoo <kmashkoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:25:30 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/09/30 14:53:56 by kmashkoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(const char *string, ...);
int		ft_putchar_va(va_list args);
int		ft_putstring_va(va_list args);
int		ft_itoa_va(va_list args);
int		ft_itoa_unsigned_va(va_list args);
char	*ft_itoa_unsigned(unsigned int n);
char	*ft_itohex(size_t n);
int		ft_itohex_va(va_list args, int k);

#endif