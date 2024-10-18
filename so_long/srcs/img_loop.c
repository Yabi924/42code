#include "so_long.h"

void    check_and_put(t_game *game, int j, int i, int x, int y)
{
    x *= 64;
    y *= 64;
    if (game->map[j][i] != '1')
        mlx_put_image_to_window(game->mlx, game->mlx_win, \
            game->mlx_bg, x, y);
    if (game->map[j][i] == '1')
        mlx_put_image_to_window(game->mlx, game->mlx_win, \
            game->mlx_wall, x, y);
    if (game->map[j][i] == 'C')
        mlx_put_image_to_window(game->mlx, game->mlx_win, \
            game->mlx_col, x, y);
}

void    loop_bg_wall(t_game *game)
{
    int i;
    int j;
    int x;
    int y;

    j = 0;
    y = 0;
    while (game->map[j])
    {
        i = 0;
        x = 0;
        while(game->map[j][i])
            check_and_put(game, j, i++, x++, y);
        j++;
        y++;
    }
}

int img_loop(t_game *game)
{
    loop_bg_wall(game);
    return (0);
}