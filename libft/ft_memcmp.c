/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:14:29 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 10:14:30 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	size_t	i;

	i = 0;
	if (buf1 == buf2 || n == 0)
		return (0);
	while (n > i)
	{
		if (((unsigned char *) buf1)[i] == ((unsigned char *) buf2)[i])
		{
			i++;
		}
		else
		{
			return ((((unsigned char *) buf1)[i])
							- ((unsigned char *) buf2)[i]);
		}
	}
	return (0);
}
