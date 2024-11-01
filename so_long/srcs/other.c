/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:36:08 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/10/31 19:36:46 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->arr_map)
	{
		while (game->arr_map[i])
			free(game->arr_map[i++]);
		free(game->arr_map);
	}
	i = 0;
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
	}
}

void	count_obj(t_game *game, int i, int j)
{
	if (game->arr_map[j][i] == 'P')
	{
		game->player_x = i;
		game->player_y = j;
		game->player_len++;
	}
	if (game->arr_map[j][i] == 'A')
	{
		game->emy_x = i;
		game->emy_y = j;
		game->emy_len++;
	}
	if (game->arr_map[j][i] == 'C')
		game->col_len++;
	if (game->arr_map[j][i] == 'E')
		game->exit_len++;
}

int	double_newline(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			return (1);
	}
	return (0);
}

void	check_position(t_game *game)
{
	if (game->emy_y == game->player_y && \
		game->emy_x == game->player_x)
		exit_lose(game);
	if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->col_len--;
	}
	if (game->map[game->player_y][game->player_x] == 'E' && \
		game->col_len == 0)
		exit_win(game);
}
