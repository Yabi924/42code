#include "so_long.h"

int main(void)
{
    void *mlx;
    void *mlx_win;

    // Initialize mlx
    mlx = mlx_init();
    if (mlx == NULL)
    {
        printf("Failed to initialize MiniLibX (mlx_init returned NULL)\n");
        return (1);
    }

    // Create new window
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    if (mlx_win == NULL)
    {
        printf("Failed to create a window\n");
        return (1);
    }

    // Start mlx loop
    mlx_loop(mlx);
    return (0);
}
