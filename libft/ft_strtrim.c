/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:15:20 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 10:15:20 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_same(char common, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == common)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	before;
	size_t	after;

	before = 0;
	if (!s1 || !set)
		return (NULL);
	after = ft_strlen(s1);
	while (ft_is_same(s1[before], set) == 1)
		before++;
	while (before < after && ft_is_same(s1[after - 1], set) == 1)
		after--;
	result = ft_substr(s1, before, after - before);
	return (result);
}
