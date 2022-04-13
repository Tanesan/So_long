/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 23:57:17 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 10:04:28 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	init_charactor_cood(t_vars *vars, int x, int y)
{
	vars->chara_x = x;
	vars->chara_y = y;
	return (0);
}

int	init_map_image(t_vars *vars, t_images *images)
{
	read_asset_images(vars, images);
	put_asset_image(vars, images);
	return (1);
}

void	ver_setup_map_info(t_vars *vars, char *result)
{
	vars->map_data = ft_split(result, '\n');
	free(result);
	vars->count = 0;
	vars->map_width = ft_strlen(vars->map_data[0]);
	vars->map_height = ft_strlen_double_pointer(vars->map_data);
}

void	ver_setup_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, \
		vars->map_width * 64, vars->map_height * 64, "minilibx");
}
