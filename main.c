/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 23:57:19 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 11:17:00 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_vars		vars;
	t_images	asset_images;
	char		*result;

	check_element_length(argc);
	check_map_shape(argv);
	result = read_map(argv);
	ver_setup_map_info(&vars, result);
	check_map_error(vars);
	ver_setup_mlx(&vars);
	init_map_image(&vars, &asset_images);
	minilibx_event_handler(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
