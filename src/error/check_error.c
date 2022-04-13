/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 23:57:34 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 10:26:17 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_rectangle(t_vars vars)
{
	if (vars.map_height == vars.map_width)
		put_error("Map must be rectangule");
}

void	check_srounded_wall_y(t_vars vars, int x, int y, int **data)
{
	if (y == 0 || y == vars.map_height - 1)
		if (vars.map_data[y][x] != '1')
			free_and_put_error(data, "Map must be srrounded 1");
}

void	check_srounded_wall_x(t_vars vars, int x, int y, int **data)
{
	if (vars.map_data[y][0] != '1' \
		|| vars.map_data[y][vars.map_width - 1] != '1')
		free_and_put_error(data, "Map must be srrounded 1");
}

void	before_and_now_check_same_lenge(int before_line_length, int x)
{
	if (before_line_length != -1 && before_line_length != x)
		put_error("Map must be rectangule");
}

int	*check_exsist_one(t_vars vars, int x, int y, int *count_element)
{
	if (vars.map_data[y][x] == 'P')
		count_element[0] += 1;
	if (vars.map_data[y][x] == 'E')
		count_element[1] += 1;
	if (vars.map_data[y][x] == 'C')
		count_element[2] = 1;
	if (vars.map_data[y][x] != '0' && vars.map_data[y][x] != 'P' &&
		vars.map_data[y][x] != 'E' && vars.map_data[y][x] != 'C' &&
		vars.map_data[y][x] != '1')
		return (NULL);
	return (count_element);
}
