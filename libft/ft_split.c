/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:14:51 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 10:14:51 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt(const char *str, char c)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[++i])
	{
		if (str[i] != c && str[i - 1] == c)
			cnt++;
	}
	if (str[0] != c)
		cnt += 1;
	return (cnt);
}

static int	*ft_get_len(const char *str, char charset)
{
	int	index;
	int	i;
	int	*w_len;

	w_len = (int *)malloc(sizeof(int) * (ft_cnt(str, charset) + 1));
	if (!w_len)
		return (NULL);
	i = -1;
	while (++i <= ft_cnt(str, charset))
		w_len[i] = 0;
	i = 0;
	index = 0;
	while (str[i] && index < ft_cnt(str, charset))
	{
		if (!(str[i] == charset))
			w_len[index]++;
		else if (i > 0 && !(str[i - 1] == charset))
			index++;
		i++;
	}
	return (w_len);
}

static void	free_all(char **p, int index)
{
	while (index >= 0)
	{
		free(p[index]);
		index--;
	}
	free(p);
}

char	**ft_malloc_in_malloc(char **dest, char charset, const char *str)
{
	int	index;
	int	*w_len;

	index = -1;
	w_len = ft_get_len(str, charset);
	if (!w_len)
	{
		free(dest);
		return (NULL);
	}
	while (++index < ft_cnt(str, charset))
	{
		dest[index] = malloc(sizeof(char) * (w_len[index] + 1));
		if (!dest[index])
		{
			free_all(dest, index);
			free(w_len);
			return (NULL);
		}
	}
	free(w_len);
	return (dest);
}

char	**ft_split(const char *str, char charset)
{
	char	**dest;
	int		i;

	i = -1;
	if (!str)
		return (NULL);
	dest = malloc(sizeof(char *) * (ft_cnt(str, charset) + 1));
	if (!dest)
		return (NULL);
	if (str[0] != '\0')
	{
		dest = ft_split_logic(str, dest, charset, i);
		if (!dest)
			return (0);
	}
	dest[ft_cnt(str, charset)] = 0;
	return (dest);
}
