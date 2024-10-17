#include "so_long.h"

int    key_handler(int key, t_game *game)
{
    if (key == esc)
        exit_game(game);
    return 0;
}

void    img_init(t_game *game)
{
    game->path_bg = "./sprites/bg.xpm";
    game->mlx_bg = mlx_xpm_file_to_image(game->mlx, game->path_bg,\
         &game->img_size, &game->img_size);

}

void game_init(t_game *game, char *map)
{
    game->img_size = 64;
    game->x = 0;
    game->y = 0;
    game->path_map = map;
    game->map_heg = 0;
    game->map_wid = 0;
    img_init(game);
    map_init(game);
}

int main(int argc, char **argv)
{
    t_game game;

    argc = 0;
    game.mlx = mlx_init();
    game_init(&game, argv[1]);
    game.mlx_win = mlx_new_window(game.mlx, \
        game.map_wid * 64, game.map_heg * 64, "so_long");
    mlx_put_image_to_window(game.mlx, game.mlx_win, game.mlx_bg, game.x, game.y);
    mlx_key_hook(game.mlx_win, key_handler, &game);
    mlx_loop(game.mlx);
}
