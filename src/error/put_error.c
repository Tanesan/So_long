/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 23:57:01 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 12:11:39 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	put_error(char *message)
{
	ft_printf("Error\n");
	ft_printf("%s\n", message);
	exit(1);
}

void	free_and_put_error(int **data, char *message)
{
	free(*data);
	ft_printf("Error\n");
	ft_printf("%s\n", message);
	exit(1);
}
