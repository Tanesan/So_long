/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:13:20 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 10:13:20 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_islower(int a)
{
	return (a >= 'a' && a <= 'z');
}

int	ft_isupper(int b)
{
	return (b >= 'A' && b <= 'Z');
}

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || ft_isupper(c) || ft_islower(c))
		return (1);
	return (0);
}
