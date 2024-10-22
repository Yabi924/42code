/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:14:56 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/10/22 19:15:02 by yyan-bin         ###   ########.fr       */
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

void	exit_game(t_game *game, int fd)
{
	if (fd == -1)
	{
		ft_printf("Map path not found\n");
		exit(0);
	}
	if (fd == -888)
	{
		ft_printf("Exit Game\n");
		free_map(game);
		exit(0);
	}
}

void	exit_map_error(t_game *game)
{
	ft_printf("map error\n");
	free_map(game);
	exit(0);
}

void	exit_lose(t_game *game)
{
	ft_printf("You Lose!! Try Again!\n");
	free_map(game);
	exit(0);
}

void	exit_win(t_game *game)
{
	ft_printf("You Win!! Congssss!\n");
	free_map(game);
	exit(0);
}
