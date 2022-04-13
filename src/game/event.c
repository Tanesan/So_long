/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 23:57:06 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 11:24:28 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	key_event_hundler(int keycode, t_vars *vars, t_images *asset_images)
{
	if (keycode == W_KEY)
		move_character(vars, 0, -1);
	if (keycode == A_KEY)
		move_character(vars, -1, 0);
	if (keycode == S_KEY)
		move_character(vars, 0, 1);
	if (keycode == D_KEY)
		move_character(vars, 1, 0);
	if (keycode == ESC_KEY)
		closed_game(vars);
	init_map_image(vars, asset_images);
	return (0);
}

void	minilibx_event_handler(t_vars *vars)
{
	mlx_hook(vars->win, ON_KEYDOWN, 0, key_event_hundler, vars);
	mlx_hook(vars->win, ON_DESTROY, 1L << 17, closed_game, vars);
}

int	move_character(t_vars *vars, char x, char y)
{
	char	action_result;

	action_result = vars->map_data[vars->chara_y + y][vars->chara_x + x];
	if (action_result == '0' || action_result == 'C')
	{
		vars->map_data[vars->chara_y][vars->chara_x] = '0';
		vars->map_data[vars->chara_y + y][vars->chara_x + x] = 'P';
		vars->chara_x += x;
		vars->chara_y += y;
		vars->count++;
		ft_printf("count: %d\n", vars->count);
		return (1);
	}
	else if (action_result == 'E' && is_collected_all_items(vars))
	{
		closed_game(vars);
		return (0);
	}
	return (0);
}

int	closed_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	is_collected_all_items(t_vars *vars)
{
	int	a;
	int	b;

	a = 0;
	while (a < vars->map_height)
	{
		b = 0;
		while (b < vars->map_width)
		{
			if (vars->map_data[a][b] == 'C')
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}
