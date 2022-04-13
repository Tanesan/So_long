/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 23:57:04 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 11:24:20 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	read_asset_images(t_vars *vars, t_images *images)
{
	int		img_width;
	int		img_height;

	images->food_img = mlx_xpm_file_to_image(vars->mlx, ITEM, \
	&img_width, &img_height);
	images->human_img = mlx_xpm_file_to_image(vars->mlx, PLAYER, \
		&img_width, &img_height);
	images->wall_img = mlx_xpm_file_to_image(vars->mlx, WALL, \
		&img_width, &img_height);
	images->grass_img = mlx_xpm_file_to_image(vars->mlx, GRASS, \
		&img_width, &img_height);
	images->goal_img = mlx_xpm_file_to_image(vars->mlx, GOAL, \
		&img_width, &img_height);
	if (images->food_img == NULL || images->human_img == NULL || \
		images->wall_img == NULL || images->grass_img == NULL || \
		images->goal_img == NULL)
		put_error(" Image is not loaded");
}

char	*read_map(char *argv[])
{
	int		fd;
	char	*line;
	char	*result;

	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		put_error("Can't read map data.");
	result = line;
	while (line)
	{
		line = get_next_line(fd);
		result = ft_gnl_strjoin(result, line);
	}
	free(line);
	return (result);
}
