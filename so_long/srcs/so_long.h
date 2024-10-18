#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __APPLE__
    #include <mlx.h>
    #define esc 53
    #define w_key 13
    #define a_key 0
    #define s_key 1
    #define d_key 2
    #define up_key 126
    #define down_key 125
    #define left_key 123
    #define right_key 124
# else
    # include "../lib/minilibx/mlx.h"
    # include "../lib/minilibx/mlx_int.h"
    #define esc 65307
    #define w_key 119
    #define a_key 97
    #define s_key 115
    #define d_key 100
    #define up_key 65362
    #define down_key 65364
    #define left_key 65361
    #define right_key 65363
# endif

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_game
{
    void    *mlx;
    void    *mlx_win;
    void    *mlx_bg;
    void    *mlx_col;
    void    *mlx_exit;
    void    *mlx_nijika;
    void    *mlx_nijika2;
    void    *mlx_ryo;
    void    *mlx_ryo2;
    void    *mlx_wall;

    char    *path_bg;
    char    *path_col;
    char    *path_exit;
    char    *path_nijika;
    char    *path_nijika2;
    char    *path_ryo;
    char    *path_ryo2;
    char    *path_wall;

    char    *path_map;
    char    **arr_map;
    int     map_heg;
    int     map_wid;

    int     img_size;

    int     ff_col;
    int     ff_exit;
    int     player_len;
    int     player_x;
    int     player_y;
    int     emy_len;
    int     emy_x;
    int     emy_y;
    int     col_len;
    int     exit_len;
}       t_game;

void    map_init(t_game *game);
void    exit_game(t_game *game);
void    exit_map_error(t_game *game);
int     img_loop(t_game *game);
void    flood_fill(t_game *game);

#endif