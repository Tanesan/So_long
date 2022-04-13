/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:07:33 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 11:40:53 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x_hex_put(int print_number, unsigned int be_execute_p, char fmt)
{
	const char		*hex_base = "0123456789abcdef";
	const char		*hex_large_base = "0123456789ABCDEF";

	if (be_execute_p == 0)
		return (print_number + ft_putchar_fd('0', 1));
	if (fmt == 'x')
		return (ft_print_hex(be_execute_p, print_number, hex_base));
	else
		return (ft_print_hex(be_execute_p, print_number, hex_large_base));
}

int	ft_printf_p_flag(va_list *ap, int print_number)
{
	unsigned long long	p;
	const char			*hex_base = "0123456789abcdef";

	p = va_arg(*ap, unsigned long long);
	print_number += ft_putstr_fd("0x", 1, 1);
	if (p == 0)
		return (print_number + ft_putchar_fd('0', 1));
	return (ft_print_hex(p, print_number, hex_base));
}

int	ft_print_flag(const char **fmt, va_list *ap, int print_number)
{
	unsigned int	x;

	if (**fmt == 'c')
		print_number += ft_putchar_fd((char)va_arg(*ap, int), 1);
	else if (**fmt == 's')
		print_number += ft_putstr_fd(va_arg(*ap, char *), 1, 1);
	else if (**fmt == 'p')
		print_number = ft_printf_p_flag(ap, print_number);
	else if (**fmt == 'd' || **fmt == 'i')
		print_number += ft_putnbr_fd(va_arg(*ap, int), 1);
	else if (**fmt == 'u')
		print_number += ft_putnbr_unsigned_fd(va_arg(*ap, unsigned int), 1);
	else if (**fmt == 'x' || **fmt == 'X')
	{
		x = va_arg(*ap, unsigned int);
		print_number = ft_x_hex_put(print_number, x, **fmt);
	}
	else if (**fmt == '%')
		print_number += ft_putchar_fd('%', 1);
	return (print_number);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		print_number;

	print_number = 0;
	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			print_number = ft_print_flag(&fmt, &ap, print_number);
			fmt++;
		}
		else
		{
			write(1, fmt, 1);
			fmt++;
			print_number++;
		}
	}
	va_end(ap);
	return (print_number);
}
