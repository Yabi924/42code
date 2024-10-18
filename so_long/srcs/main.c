#include "so_long.h"

void	moving(t_game *game, int key)
{
	if (key == W_KEY || key == UP_KEY)
	{
		if (game->map[game->player_y - 1][game->player_x] != '1')
			game->player_y--;
		game->move_count++;
	}
	else if (key == A_KEY || key == LEFT_KEY)
	{
		if (game->map[game->player_y][game->player_x - 1] != '1')
			game->player_x--;
		game->move_count++;
	}
	else if (key == S_KEY || key == DOWN_KEY)
	{
		if (game->map[game->player_y + 1][game->player_x] != '1')
			game->player_y++;
		game->move_count++;
	}
	else if (key == D_KEY || key == RIGHT_KEY)
	{
		if (game->map[game->player_y][game->player_x + 1] != '1')
			game->player_x++;
		game->move_count++;
	}
}

int	key_handler(int key, t_game *game)
{
	if (key == ESC)
		exit_game(game);
	else if (key == W_KEY || key == A_KEY || key == S_KEY || \
		key == D_KEY || key == LEFT_KEY || key == RIGHT_KEY || \
		key == DOWN_KEY || key == UP_KEY)
		moving(game, key);
	return (0);
}

void	img_init(t_game *game)
{
	game->path_bg = "./sprites/bg.xpm";
	game->mlx_bg = mlx_xpm_file_to_image(game->mlx, game->path_bg, \
		&game->img_size, &game->img_size);
	game->path_col = "./sprites/col.xpm";
	game->mlx_col = mlx_xpm_file_to_image(game->mlx, game->path_col, \
		&game->img_size, &game->img_size);
	game->path_exit = "./sprites/exit.xpm";
	game->mlx_exit = mlx_xpm_file_to_image(game->mlx, game->path_exit, \
		&game->img_size, &game->img_size);
	game->path_wall = "./sprites/wall.xpm";
	game->mlx_wall = mlx_xpm_file_to_image(game->mlx, game->path_wall, \
		&game->img_size, &game->img_size);
}

void	game_init(t_game *game, char *map)
{
	game->img_size = 64;
	game->path_map = map;
	game->map_heg = 0;
	game->map_wid = 0;
	game->ff_col = 0;
	game->ff_exit = 0;
	game->emy_len = 0;
	game->emy_x = 0;
	game->emy_y = 0;
	game->player_len = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->col_len = 0;
	game->exit_len = 0;
	game->animation_count = 0;
	game->move_count = 0;
	img_init(game);
	map_init(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("please follow fomat: ./so_long map/*.ber\n");
		return (0);
	}
	game.mlx = mlx_init();
	game_init(&game, argv[1]);
	if (!game.mlx)
	{
		ft_printf("mlx_init return NULL\nplease check server\n");
		return (0);
	}
	game.mlx_win = mlx_new_window(game.mlx, \
	game.map_wid * 64, game.map_heg * 64, "so_long");
	mlx_loop_hook(game.mlx, img_loop, &game);
	mlx_key_hook(game.mlx_win, key_handler, &game);
	mlx_loop(game.mlx);
}
