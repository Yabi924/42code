/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:26:21 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/10/22 19:26:23 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>

# ifdef __APPLE__
#  include <mlx.h>
#  define ESC 53
#  define W_KEY 13
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2
#  define UP_KEY 126
#  define DOWN_KEY 125
#  define LEFT_KEY 123
#  define RIGHT_KEY 124
# else
#  include "../lib/minilibx/mlx.h"
#  include "../lib/minilibx/mlx_int.h"
#  define ESC 65307
#  define W_KEY 119
#  define A_KEY 97
#  define S_KEY 115
#  define D_KEY 100
#  define UP_KEY 65362
#  define DOWN_KEY 65364
#  define LEFT_KEY 65361
#  define RIGHT_KEY 65363
# endif

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_bg;
	void	*mlx_col;
	void	*mlx_exit;
	void	*mlx_player;
	void	*mlx_enemy;
	void	*mlx_wall;

	char	*path_bg;
	char	*path_col;
	char	*path_exit;
	char	*path_player;
	char	*path_enemy;
	char	*path_wall;

	char	*path_map;
	char	**arr_map;
	char	**map;
	int		map_heg;
	int		map_wid;

	int		img_size;

	int		ff_col;
	int		ff_exit;
	int		player_len;
	int		player_x;
	int		player_y;
	int		emy_len;
	int		emy_x;
	int		emy_y;
	int		col_len;
	int		exit_len;

	int		animation_count;
	int		move_count;
	int		a_move_count;
	int		random;
	int		fd;
}	t_game;

void	map_init(t_game *game);
void	flood_fill(t_game *game);
void	exit_game(t_game *game, int fd);
void	exit_map_error(t_game *game);
void	exit_lose(t_game *game);
void	exit_win(t_game *game);
void	player_move(t_game *game, int key);
int		img_loop(t_game *game);
void	check_position(t_game *game);
void	emy_move(t_game *game);

#endif
