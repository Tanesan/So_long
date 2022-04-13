/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 23:56:57 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 10:17:31 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static	void	put_asset_in_while(t_vars *vars, t_images *images, int x, int y)
{
	if (vars->map_data[y][x] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		images->food_img, 64 * x, 64 * y);
	else if (vars->map_data[y][x] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		images->wall_img, 64 * x, 64 * y);
	else if (vars->map_data[y][x] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		images->grass_img, 64 * x, 64 * y);
	else if (vars->map_data[y][x] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, \
		images->grass_img, 64 * x, 64 * y);
		mlx_put_image_to_window(vars->mlx, vars->win, \
		images->human_img, 64 * x, 64 * y);
		init_charactor_cood(vars, x, y);
	}
	else if (vars->map_data[y][x] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		images->goal_img, 64 * x, 64 * y);
}

void	put_asset_image(t_vars *vars, t_images *images)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars->map_height)
	{
		x = 0;
		while (x < vars->map_width)
		{
			put_asset_in_while(vars, images, x, y);
			x++;
		}
		y++;
	}
}
