// #include "./srcs/so_long.h"

// gcc test.c -lmlx -framework OpenGL -framework AppKit -o test
#include <mlx.h>

typedef struct  s_game
{
    void    *mlx;
    void    *window;
    int     color;
}               t_game;

// Function to be called continuously in the loop
int game_loop(t_game *game)
{
    // Example: change background color every frame
    game->color += 0x010000; // Modify the color value

    // Draw the new color on the window
    mlx_clear_window(game->mlx, game->window);
    mlx_string_put(game->mlx, game->window, 50, 50, game->color, "Hello, MLX!");

    return (0);
}

int main(void)
{
    t_game game;

    // Initialize MLX
    game.mlx = mlx_init();

    // Create a window
    game.window = mlx_new_window(game.mlx, 800, 600, "MLX Hook Example");

    // Initialize color to start with
    game.color = 0x00FF0000; // Red color

    // Set up the loop hook
    mlx_loop_hook(game.mlx, (int (*)())game_loop, &game);

    // Start the main loop
    mlx_loop(game.mlx);

    return (0);
}



// // gcc test.c ./lib/libft/libft.a ./lib/ft_printf/libftprintf.a -o test

// void    print_arr(char **s, int i)
// {
//     int j = 0;
//     while(j < i)
//     {
//         ft_printf("%s\n", s[j]);
//         j++;
//     }
// }

// void game_init(t_game *game, char *map)
// {
//     game->img_size = 64;
//     game->x = 0;
//     game->y = 0;
//     game->path_map = map;
//     game->map_heg = 0;
//     game->map_wid = 0;
//     // img_init(game);
// }

// // void    free_arr(char **str)
// // {
// //     int i;

// //     i = 0;
// //     while (str[i])
// //         free(str[i++]);
// //     free(str);
// // }

// // //check col
// // int check_wid_same(char **s)
// // {
// //     int i;
// //     int j;

// //     i = ft_strlen(s[0]);
// //     j = 0;
// //     while (s[j])
// //     {
// //         if (ft_strlen(s[j]) != i)
// //             return (0);
// //         j++;
// //     }
// //     return (i);
// // }

// // void    read_map(t_game *game)
// // {
// //     int     fd;
// //     char    *map;
// //     char    *map_temp;
// //     char    *readd;
// //     char    **arr_map;

// //     map = NULL;
// //     fd = open(game->path_map, O_RDONLY);
// //     if (fd == -1)
// //         return ; //open error
// //     while ((readd = get_next_line(fd)))
// //     {
// //         if (!map)
// //             map = ft_strdup(readd);
// //         else 
// //         {
// //             map_temp = ft_strjoin(map, readd);
// //             free(map);
// //             map = map_temp;
// //         }
// //         game->map_col++;
// //         free(readd);
// //     }
// //     close(fd);
// //     if (*map == '\0')
// //     {
// //         ft_printf("map error\n");
// //         free(map);
// //         return ; //map error
// //     }
// //     arr_map = ft_split(map, '\n');
// //     game->map_wid = check_wid_same(arr_map);
// //     if (game->map_wid == 0)
// //         ft_printf("map wid error\n");
// //     print_arr(arr_map, game->map_col);
// //     ft_printf("col:%d wid:%d\n", game->map_col, game->map_wid);
// //     free_arr(arr_map);
// //     free(map);
// // }


// //free arr
// void    free_arr(char **str)
// {
//     int i;

//     i = 0;
//     while (str[i])
//         free(str[i++]);
//     free(str);
// }

// //check col
// int check_wid_same(char **s)
// {
//     int i;
//     int j;
//     size_t wid;

//     wid = ft_strlen(s[0]);
//     j = 0;
//     while (s[j])
//     {
//         if (ft_strlen(s[j]) != wid)
//             return (0);
//         j++;
//     }
//     return (wid);
// }

// void    read_map(t_game *game)
// {
//     int     fd;
//     char    *map;
//     char    *map_temp;
//     char    *readd;

//     map = NULL;
//     fd = open(game->path_map, O_RDONLY);
//     if (fd == -1)
//         return ; //open error
//     while ((readd = get_next_line(fd)))
//     {
//         if (!map)
//             map = ft_strdup(readd);
//         else 
//         {
//             map_temp = ft_strjoin(map, readd);
//             free(map);
//             map = map_temp;
//         }
//         game->map_heg++;
//         free(readd);
//     }
//     close(fd);
//     if (*map == '\0')
//     {
//         ft_printf("map error\n");
//         free(map);
//         return ; //map error
//     }
//     game->arr_map = ft_split(map, '\n');
//     game->map_wid = check_wid_same(game->arr_map);
//     if (game->map_wid == 0)
//         return ; //map wid error
//     print_arr(game->arr_map, game->map_heg);
//     free_arr(game->arr_map);
//     free(map);
// }

// int main()
// {
//     t_game game;
//     game_init(&game, "map/1.ber");
//     read_map(&game);
//     ft_printf("wid:%d heg:%d", game.map_wid, game.map_heg);
//     return 0;
// }
