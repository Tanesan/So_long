/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:12:02 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 10:12:03 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	i_calclate(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ') || (str[i] == '\f') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\r') || (str[i] == '\t'))
		i++;
	return (i);
}

long	ft_negative_check(long negative)
{
	if (negative % 2 == 0)
		negative = 1;
	else
		negative = -1;
	return (negative);
}

int	ft_atoi(const char *str)
{
	long	negative;
	long	result;
	int		i;

	negative = 0;
	result = 0;
	i = i_calclate(str);
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			negative += 1;
	negative = ft_negative_check(negative);
	while ((unsigned char)str[i] >= '0' && (unsigned char)str[i] <= '9')
	{
		if (((result * 10) + (unsigned char)str[i] - '0' < result)
			&& (negative == 1))
			return (-1);
		else if (((result * 10) + (unsigned char)str[i] - '0' < result)
			&& (negative == -1))
			return (0);
		result = (result * 10) + (unsigned char)str[i] - '0';
		i++;
	}
	result *= negative;
	return ((int)result);
}
