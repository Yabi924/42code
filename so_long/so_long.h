#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __APPLE__
    #include <mlx.h>
# elif defined (__LINUX__)
    # include "lib/minilibx/mlx.h"
    # include "lib/minilibx/mlx_int.h"
# endif 

# include "lib/libft/libft.h"
# include <stdio.h>
# include <unistd.h>

#endif