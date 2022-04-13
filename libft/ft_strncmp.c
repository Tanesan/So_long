/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:15:13 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 10:15:13 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	j;

	j = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[j] != '\0'
		&& (unsigned char)s2[j] != '\0' && j < n - 1)
	{
		if ((unsigned char)s1[j] != (unsigned char)s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		j++;
	}
	return ((unsigned char)s1[j] - (unsigned char)s2[j]);
}
