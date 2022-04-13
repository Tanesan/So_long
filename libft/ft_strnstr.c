/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:15:14 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 10:15:15 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	a;
	size_t	b;
	size_t	c;

	a = 0;
	b = 0;
	if (ft_strlen(big) < ft_strlen(little))
		return (NULL);
	if ((!little && !big) || *little == '\0')
		return ((char *)big);
	while (big[a] != '\0' && len > a)
	{
		if (big[a] == little[0])
		{
			c = a;
			while (big[c++] == little[b++] || !big[c])
				if (!little[b] && len >= a && len >= c)
					return ((char *)big + c - b);
			b = 0;
		}
		a++;
	}
	return (NULL);
}
