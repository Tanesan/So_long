/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:13:52 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 10:13:52 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	get_digit2(unsigned int n)
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

void	ft_str_slide(char *str)
{
	size_t	length;

	length = ft_strlen(str) - 1;
	while (length != (size_t) - 1)
	{
		str[length + 1] = str[length];
		length--;
	}
	str[0] = '-';
}

void	ft_str_reverse(char *str)
{
	size_t	length;
	size_t	i;
	char	tmp;

	length = ft_strlen(str);
	i = 0;
	while (i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
		i++;
	}
}

char	*ft_atoi_logic(char *result, int minas, int n, int digits)
{
	int	a;

	a = 0;
	result[digits] = '\0';
	result[0] = '0';
	while (n != 0)
	{
		result[a] = n % 10 + '0';
		n /= 10;
		a++;
	}
	ft_str_reverse(result);
	if (minas == 1)
		ft_str_slide(result);
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		minas;
	int		digits;

	minas = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		minas = 1;
		n = n * (-1);
	}
	digits = get_digit2(n);
	result = (char *)malloc(sizeof(char) * (digits + minas + 1));
	if (!result)
		return (NULL);
	result = ft_atoi_logic(result, minas, n, digits);
	result[digits + 1] = '\0';
	return (result);
}
