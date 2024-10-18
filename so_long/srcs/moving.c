#include "so_long.h"

void    moving(t_game *game, int key)
{
    if (key == w_key || key == up_key)
    {
        if (game->map[game->player_y - 1][game->player_x] != '1')
            game->player_y--;
    }
    else if (key == a_key || key == left_key)
    {
        if (game->map[game->player_y][game->player_x - 1] != '1')
            game->player_x--;
    }
    else if (key == s_key || key == down_key)
    {
        if (game->map[game->player_y + 1][game->player_x] != '1')
            game->player_y++;
    }
    else if (key == d_key || key == right_key)
    {
        if (game->map[game->player_y][game->player_x + 1] != '1')
            game->player_x++;
    }
}
