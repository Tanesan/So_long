/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:08:18 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 12:04:07 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_digit_minus_supported(int n)
{
	int	digit;

	digit = 1;
	if (n > 0)
	{
		while (n > 9)
		{
			n /= 10;
			++digit;
		}
	}
	else if (n < 0)
	{
		++digit;
		while (n > 9 || n < -9)
		{
			n /= -10;
			++digit;
		}
	}
	return (digit);
}

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_bzero(void *buf, size_t n)
{
	size_t	a;

	a = 0;
	while (n != a)
	{
		((char *)buf)[a] = 0;
		a++;
	}
}

int	ft_print_hex(unsigned long long p, int pn, const char *hex_base)
{
	char	hex[21];
	int		sort_gravity;
	int		l;
	int		i;

	i = 0;
	sort_gravity = 0;
	ft_bzero(hex, 21);
	while (p >= 1)
	{
		hex[i] = hex_base[p % 16];
		p /= 16;
		i++;
		pn++;
	}
	while (sort_gravity < i)
	{
		l = sort_gravity - 1;
		while (++l < i)
			ft_swap(&hex[sort_gravity], &hex[l]);
		sort_gravity++;
	}
	ft_putstr_fd(hex, 1, 0);
	return (pn);
}
