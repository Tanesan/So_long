/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:12:19 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 10:13:08 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*p;
	size_t	a;

	if (n == 0 || size == 0)
		return (NULL);
	p = (char *)malloc(size * n);
	if (!p)
		return (NULL);
	a = 0;
	while (size * n != a)
	{
		((char *)p)[a] = (unsigned char) '\0';
		a++;
	}
	return (p);
}
