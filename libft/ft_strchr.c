/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:14:54 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 10:14:54 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_logic(const char *str, char **dest, char charset, int i)
{
	int	j;
	int	index;

	j = 0;
	index = 0;
	dest = ft_malloc_in_malloc(dest, charset, str);
	if (!dest)
		return (NULL);
	while (str[++i])
	{
		if (str[i] != charset)
		{
			dest[index][j] = str[i];
			j++;
		}
		else if (i > 0 && str[i - 1] != charset)
		{
			dest[index++][j] = 0;
			j = 0;
		}
	}
	if (str[i - 1] != charset)
		dest[index][j] = 0;
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
