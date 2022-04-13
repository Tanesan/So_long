/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:38:47 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 11:54:06 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	a;
	char	*str;

	i = 0;
	a = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= start && len > a)
		{
			str[a] = s[i];
			a++;
		}
		i++;
	}
	str[a] = '\0';
	return (str);
}

char	*ft_gnl_strchr(const char *s, int c, int is_before)
{
	char	*result;
	char	*tmp;
	size_t	i;

	i = 0;
	result = NULL;
	tmp = (char *)s;
	if (c == '\0')
		return ((char *)s);
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			result = ((char *)++s);
			break ;
		}
		s++;
		i++;
	}
	if (is_before == 1)
		return (ft_gnl_substr(tmp, 0, ++i));
	if (result && *result == '\0')
		return (NULL);
	return (result);
}

void	ft_gnl_bzero(void *b, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = b;
	i = 0;
	while (i++ < n)
		*dest++ = 0;
}
