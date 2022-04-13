/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:15:05 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 10:15:05 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (!dst && !src)
		return (0);
	while (src[i] != '\0')
		i++;
	if (size == 0)
		return (i);
	while (x < (size - 1) && src[x] != '\0')
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
	return (i);
}
