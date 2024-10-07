#include <mlx.h>
#include <stdio.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
    if (!mlx)
        printf("fuck la\n");
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    if (!mlx_win)
        printf("fuck\n");
	mlx_loop(mlx);
}
