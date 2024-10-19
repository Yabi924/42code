#include "so_long.h"

// void    del_img(t_game *game)
// {
//     if (game->mlx_nijika)
//         mlx_destroy_image(game->mlx, game->mlx_nijika);
//     if (game->mlx_ryo)
//         mlx_destroy_image(game->mlx, game->mlx_ryo);
//     if (game->mlx_bg)
//         mlx_destroy_image(game->mlx, game->mlx_bg);
//     if (game->mlx_col)
//         mlx_destroy_image(game->mlx, game->mlx_col);
//     if (game->mlx_exit)
//         mlx_destroy_image(game->mlx, game->mlx_exit);
//     if (game->mlx_wall)
//         mlx_destroy_image(game->mlx, game->mlx_wall);
//     if (game->mlx_win)
//         mlx_destroy_window(game->mlx, game->mlx_win);
// }

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
