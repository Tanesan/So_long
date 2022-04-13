/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 23:57:34 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 10:32:15 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static	void	while_cheack_map(t_vars vars, int x, int y, int **count_element)
{
	int	before_line_length;

	before_line_length = vars.map_width;
	while (y < vars.map_height)
	{
		x = 0;
		while (x < vars.map_width)
		{
			check_srounded_wall_y(vars, x, y, count_element);
			*count_element = check_exsist_one(vars, x, y, *count_element);
			if (*count_element == NULL)
				free_and_put_error(count_element, \
				"You can use P, E, C, 0, 1 to map.");
			x++;
		}
		before_and_now_check_same_lenge(before_line_length, x);
		before_line_length = x;
		check_srounded_wall_x(vars, x, y, count_element);
		y++;
	}
}

void	check_map_condition(t_vars vars)
{
	int	x;
	int	y;
	int	*count_element;

	y = 0;
	count_element = (int *)ft_calloc(sizeof(char), 3);
	if (!count_element)
		put_error("Calloc mistake!");
	ft_bzero(count_element, 3);
	while_cheack_map(vars, x, y, &count_element);
	if (count_element[0] != 1 || count_element[1] != 1 || count_element[2] != 1)
		free_and_put_error(&count_element, \
				"Map has least 1 each charactor");
	free(count_element);
}

int	check_map_error(t_vars vars)
{
	check_rectangle(vars);
	check_map_condition(vars);
	return (1);
}

void	check_map_shape(char *argv[])
{
	char	**format;

	format = ft_split(argv[1], '.');
	if (ft_strncmp(format[ft_strlen_double_pointer(format) - 1], "ber", 4) != 0)
	{
		free(format);
		put_error("Map format is not ok.");
		exit(1);
	}
	free(format);
}

void	check_element_length(int argc)
{
	if (argc != 2)
		put_error("Argument must be 2 functions.");
}
