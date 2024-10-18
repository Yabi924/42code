#include "so_long.h"

void    check_position(t_game *game)
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
    if (game->map[j][i] == 'E')
    {
        if (game->col_len == 0)
            mlx_put_image_to_window(game->mlx, game->mlx_win, \
            game->mlx_exit, x, y);
    }
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

void    loop_char(t_game *game)
{   
    if (game->animation_count % 32 < 16)
    {
        game->path_nijika = "./sprites/nina.xpm";
        game->path_ryo = "./sprites/rotania.xpm";
        if (game->mlx_nijika)
            mlx_destroy_image(game->mlx, game->mlx_nijika);
        if (game->mlx_ryo)
            mlx_destroy_image(game->mlx, game->mlx_ryo);
    }
    if (game->animation_count % 32 >= 16)
    {
        game->path_nijika = "./sprites/nina2.xpm";
        game->path_ryo = "./sprites/rotania2.xpm";
        if (game->mlx_nijika)
            mlx_destroy_image(game->mlx, game->mlx_nijika);
        if (game->mlx_ryo)
            mlx_destroy_image(game->mlx, game->mlx_ryo);
    }
    game->mlx_nijika = mlx_xpm_file_to_image(game->mlx, \
            game->path_nijika, &game->img_size, &game->img_size);
    if (game->emy_len == 1)
            game->mlx_ryo = mlx_xpm_file_to_image(game->mlx, \
                game->path_ryo, &game->img_size, &game->img_size);
}

int img_loop(t_game *game)
{
    loop_bg_wall(game);
    loop_char(game);
    check_position(game);
    mlx_put_image_to_window(game->mlx, game->mlx_win, \
        game->mlx_nijika, game->player_x * 64, game->player_y * 64);
    if (game->emy_len == 1)
        mlx_put_image_to_window(game->mlx, game->mlx_win, \
        game->mlx_ryo, game->emy_x * 64, game->emy_y * 64);
    mlx_string_put(game->mlx, game->mlx_win, 1 * 64, 64, \
        0xFF0000, "Moving Count:");
    game->animation_count++;
    return (0);
}