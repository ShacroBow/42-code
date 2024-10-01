/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:25:30 by kmashkoo          #+#    #+#             */
/*   Updated: 2024/10/01 15:30:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
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
int		ft_itohex_va(va_list args);
int		ft_itohex_cap_va(va_list args);
int		ft_itohex_point_va(va_list args);
int		ft_failcheck_printf(int k);

#endif