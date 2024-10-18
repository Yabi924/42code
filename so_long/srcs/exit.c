#include "so_long.h"

void    del_img(t_game *game)
{
    if (game->mlx_nijika)
        mlx_destroy_image(game->mlx, game->mlx_nijika);
    if (game->mlx_ryo)
        mlx_destroy_image(game->mlx, game->mlx_ryo);
    if (game->mlx_bg)
        mlx_destroy_image(game->mlx, game->mlx_bg);
    if (game->mlx_col)
        mlx_destroy_image(game->mlx, game->mlx_col);
    if (game->mlx_exit)
        mlx_destroy_image(game->mlx, game->mlx_exit);
    if (game->mlx_wall)
        mlx_destroy_image(game->mlx, game->mlx_wall);
    if (game->mlx_win)
        mlx_destroy_window(game->mlx, game->mlx_win);
}

void    free_map(t_game *game)
{
    int i;

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
    // del_img(game);
}

void    exit_game(t_game *game)
{
    free_map(game);
    exit(0);
}

void    exit_map_error(t_game *game)
{
    ft_printf("map error\n");
    free_map(game);
    exit(0);
}
