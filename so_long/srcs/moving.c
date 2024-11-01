/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:20:18 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/10/22 19:20:20 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move(t_game *game, int key)
{
	if ((key == W_KEY || key == UP_KEY) && \
		game->map[game->player_y - 1][game->player_x] != '1')
	{
		game->player_y--;
		game->move_count++;
	}
	else if ((key == A_KEY || key == LEFT_KEY) && \
		(game->map[game->player_y][game->player_x - 1] != '1'))
	{
		game->player_x--;
		game->move_count++;
	}
	else if ((key == S_KEY || key == DOWN_KEY) && \
		(game->map[game->player_y + 1][game->player_x] != '1'))
	{
		game->player_y++;
		game->move_count++;
	}
	else if ((key == D_KEY || key == RIGHT_KEY) && \
		(game->map[game->player_y][game->player_x + 1] != '1'))
	{
		game->player_x++;
		game->move_count++;
	}
}

void	stoping_handler(t_game *game, int *m)
{
	if (*m == 0 && game->map[game->emy_y - 1][game->emy_x] != '1')
	{
		game->emy_y--;
		*m = 3;
	}
	else if (*m == 3 && game->map[game->emy_y][game->emy_x - 1] != '1')
	{
		game->emy_x--;
		*m = 0;
	}
	else if (*m == 2 && game->map[game->emy_y][game->emy_x + 1] != '1')
	{
		game->emy_x++;
		*m = 1;
	}
	else if (*m == 1 && game->map[game->emy_y + 1][game->emy_x] != '1')
	{
		game->emy_y++;
		*m = 2;
	}
}

unsigned int	randomizer(t_game *game)
{
	unsigned int	random;

	random = (game->random * 1103515245 + 12345) % 2147483648;
	return (random % 4);
}

void	emy_move(t_game *game)
{
	int			m;
	static int	stoping = 0;

	game->a_move_count++;
	m = randomizer(game);
	if (stoping == 2)
	{
		stoping_handler(game, &m);
		stoping = 0;
	}
	if (m == 3 && game->map[game->emy_y][game->emy_x + 1] != '1')
		game->emy_x++;
	else if (m == 2 && game->map[game->emy_y][game->emy_x - 1] != '1')
		game->emy_x--;
	else if (m == 1 && game->map[game->emy_y - 1][game->emy_x] != '1')
		game->emy_y--;
	else if (m == 0 && game->map[game->emy_y + 1][game->emy_x] != '1')
		game->emy_y++;
	else
		stoping++;
}
