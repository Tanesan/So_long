/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:16:07 by ktanemur          #+#    #+#             */
/*   Updated: 2022/02/23 18:22:10 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd, int is_null_string)
{
	size_t	i;

	i = 0;
	if (s == NULL && is_null_string)
		s = "(null)";
	else if (s == NULL)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	while (s[i] != 0)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}
