/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 23:57:08 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 12:09:27 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sysexits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "mlx/mlx.h"
# include <stdio.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define PLAYER "./img/human.xpm"
# define ITEM "./img/food.xpm"
# define WALL "./img/tree.xpm"
# define GRASS "./img/grass.xpm"
# define GOAL "./img/goal.xpm"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		chara_x;
	int		chara_y;
	char	**map_data;
	int		map_width;
	int		map_height;
	int		count;
}		t_vars;

typedef struct s_images
{
	void	*food_img;
	void	*human_img;
	void	*wall_img;
	void	*grass_img;
	void	*goal_img;
}		t_images;

enum
{
	ON_KEYDOWN = 2,
	ON_DESTROY = 17,
	W_KEY = 13,
	A_KEY = 0,
	S_KEY = 1,
	D_KEY = 2,
	ESC_KEY = 53
};

void	put_error(char *messange);
size_t	ft_strlen_double_pointer(char **s);
void	check_rectangle(t_vars vars);
void	check_srounded_wall_x(t_vars vars, int x, int y, int **data);
void	check_srounded_wall_y(t_vars vars, int x, int y, int **data);
void	before_and_now_check_same_lenge(int before_line_length, int x);
void	check_map_condition(t_vars vars);
int		check_map_error(t_vars vars);
int		*check_exsist_one(t_vars vars, int x, int y, int *count_element);
void	check_element_length(int argc);
void	check_map_shape(char *argv[]);
void	put_asset_image(t_vars *vars, t_images *images);
void	read_asset_images(t_vars *vars, t_images *images);
char	*read_map(char *argv[]);
int		key_event_hundler(int keycode, t_vars *vars, t_images *asset_images);
void	minilibx_event_handler(t_vars *vars);
int		move_character(t_vars *vars, char x, char y);
int		closed_game(t_vars *vars);
int		is_collected_all_items(t_vars *vars);
int		init_charactor_cood(t_vars *vars, int x, int y);
int		init_map_image(t_vars *vars, t_images *images);
void	ver_setup_map_info(t_vars *vars, char *result);
void	ver_setup_mlx(t_vars *vars);
void	free_and_put_error(int **data, char *messange);

#endif
