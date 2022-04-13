/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 23:57:25 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 10:16:18 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

size_t	ft_strlen_double_pointer(char **s)
{
	size_t	len;

	len = 0;
	if (!*s)
		return (0);
	while (*(s + len))
		len++;
	return (len);
}
