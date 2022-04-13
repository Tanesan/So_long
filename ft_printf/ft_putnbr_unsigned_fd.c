/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:51:39 by ktanemur          #+#    #+#             */
/*   Updated: 2022/02/23 18:21:40 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_digit_unsigned(unsigned int n)
{
	unsigned int	digit;

	digit = 1;
	while (n > 9)
	{
		n /= 10;
		++digit;
	}
	return ((int)digit);
}

int	ft_putnbr_unsigned_fd(unsigned int nb, int fd)
{
	int		digit;
	int		result;
	char	will_put[11];
	int		i;
	char	a;

	i = 0;
	result = get_digit_unsigned(nb);
	digit = result - 1;
	while ((nb / 10) > 0)
	{
		a = nb % 10 + '0';
		will_put[i] = a;
		nb = nb / 10;
		i++;
	}
	will_put[i] = nb + '0';
	while (digit >= 0)
	{
		ft_putchar_fd(will_put[digit], fd);
		digit--;
	}
	return (result);
}
