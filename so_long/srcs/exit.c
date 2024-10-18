#include "so_long.h"

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
