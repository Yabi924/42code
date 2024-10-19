#include "so_long.h"

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

void	player_move(t_game *game, int key)
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

unsigned int randomizer(t_game *game)
{
    unsigned int random;

    random = (game->random * 1103515245 + 12345) % 2147483648;
    return (random % 4);
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

void    emy_move(t_game *game)
{
    int m;
	static int stoping = 0;

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
