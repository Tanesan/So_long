/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:15:09 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 10:15:10 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	g;
	char	*result;

	if (!s)
		return (NULL);
	g = ft_strlen(s);
	i = 0;
	result = (char *)malloc(sizeof(char) * (g + 1));
	if (!result)
		return (0);
	while (i < g)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[g] = '\0';
	return (result);
}
