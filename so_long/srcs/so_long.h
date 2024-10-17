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

    char    *path_col;
    char    *path_bg;
    char    *path_map;

    int     img_size;
    int     win_size;

    int     x;
    int     y;
    int     map_heg;
    int     map_wid;

    char    **arr_map;
}       t_game;

void    map_init(t_game *game);
void    exit_game(t_game *game);
void    exit_map_error(t_game *game);

#endif