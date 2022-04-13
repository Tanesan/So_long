/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:54:14 by ktanemur          #+#    #+#             */
/*   Updated: 2022/02/21 23:12:35 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	get_digit(unsigned int n)
{
	unsigned int	digit;

	digit = 1;
	while (n > 9)
	{
		n /= 10;
		++digit;
	}
	return (digit);
}

int	minas_remove(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * (-1);
	}
	return (nb);
}

int	ft_print_low_limit(int a, int fd)
{
	if (a == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putchar_fd('1', fd);
		ft_putchar_fd('4', fd);
		ft_putchar_fd('7', fd);
		ft_putchar_fd('4', fd);
		ft_putchar_fd('8', fd);
		ft_putchar_fd('3', fd);
		ft_putchar_fd('6', fd);
		ft_putchar_fd('4', fd);
		ft_putchar_fd('8', fd);
		return (0);
	}
	return (1);
}

int	ft_putnbr_fd(int nb, int fd)
{
	int		keta;
	char	name[11];
	int		i;
	int		result;
	char	a;

	i = 0;
	result = get_digit_minus_supported(nb);
	if (ft_print_low_limit(nb, fd) == 0)
		return (result);
	keta = result;
	if (nb < 0)
		keta -= 1;
	nb = minas_remove(nb, fd);
	while ((nb / 10) > 0)
	{
		a = nb % 10 + '0';
		name[i] = a;
		nb = nb / 10;
		i++;
	}
	name[i] = nb + '0';
	while (--keta >= 0)
		ft_putchar_fd(name[keta], fd);
	return (result);
}
