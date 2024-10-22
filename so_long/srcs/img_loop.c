/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:16:43 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/10/22 19:16:44 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_and_put(t_game *game, char c, int x, int y)
{
	x *= 64;
	y *= 64;
	if (c != '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->mlx_bg, x, y);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->mlx_wall, x, y);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->mlx_col, x, y);
	if (c == 'E')
	{
		if (game->col_len == 0)
			mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->mlx_exit, x, y);
	}
}

void	loop_bg_wall(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	j = 0;
	y = 0;
	while (game->map[j])
	{
		i = 0;
		x = 0;
		while (game->map[j][i])
			check_and_put(game, game->map[j][i++], x++, y);
		j++;
		y++;
	}
}

void	loop_emy(t_game *game)
{
	static int	frame = 0;

	game->random++;
	game->random = game->random * game->random + \
		(game->move_count + game->a_move_count + 1);
	if (frame % 8 == 0)
		emy_move(game);
	frame++;
}

void	loop_char(t_game *game)
{
	if (game->animation_count % 32 < 16)
	{
		game->path_player = "./sprites/rotania1.xpm";
		game->path_enemy = "./sprites/nina1.xpm";
	}
	if (game->animation_count % 32 >= 16)
	{
		game->path_player = "./sprites/rotania2.xpm";
		game->path_enemy = "./sprites/nina2.xpm";
	}
	game->mlx_player = mlx_xpm_file_to_image(game->mlx, \
		game->path_player, &game->img_size, &game->img_size);
	if (game->emy_len == 1)
		game->mlx_enemy = mlx_xpm_file_to_image(game->mlx, \
			game->path_enemy, &game->img_size, &game->img_size);
}

int	img_loop(t_game *game)
{
	char	*move_count;

	loop_bg_wall(game);
	loop_char(game);
	check_position(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	game->mlx_player, game->player_x * 64, game->player_y * 64);
	if (game->emy_len == 1)
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->mlx_enemy, game->emy_x * 64, game->emy_y * 64);
	mlx_string_put(game->mlx, game->mlx_win, 1, 16, \
		4444444, "Moving Count:");
	move_count = ft_itoa(game->move_count);
	mlx_string_put(game->mlx, game->mlx_win, 130, 16, \
		4444444, move_count);
	free(move_count);
	if (game->emy_len)
		loop_emy(game);
	game->animation_count++;
	return (0);
}
