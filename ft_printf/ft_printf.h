/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:16:39 by ktanemur          #+#    #+#             */
/*   Updated: 2022/02/23 18:09:08 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_putchar_fd(char c, int fd);

int		ft_putnbr_fd(int nb, int fd);

int		get_digit_unsigned(unsigned int n);

int		ft_putnbr_unsigned_fd(unsigned int nb, int fd);

int		get_digit_minus_supported(int n);

void	ft_swap(char *a, char *b);

int		ft_putstr_fd(char *s, int fd, int is_null_string);

int		ft_printf(const char *fmt, ...);

int		ft_print_hex(unsigned long long p, int pn, const char *hex_base);

#endif