#include "so_long.h"

void	fill(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map_wid || y >= game->map_heg)
		return ;
	if (game->arr_map[y][x] == '1' || game->arr_map[y][x] == 'F')
		return ;
	if (game->arr_map[y][x] == 'C')
		game->ff_col++;
	if (game->arr_map[y][x] == 'E')
		game->ff_exit++;
	game->arr_map[y][x] = 'F';
	fill(game, x, y + 1);
	fill(game, x + 1, y);
	fill(game, x - 1, y);
	fill(game, x, y - 1);
}

void	flood_fill(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	fill(game, x, y);
	if (game->ff_exit != 1 || game->ff_col != game->col_len)
		exit_map_error(game);
}
