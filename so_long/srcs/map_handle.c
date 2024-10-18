#include "so_long.h"

int	check_wid_same(char **s)
{
	int		j;
	size_t	wid;

	if (!s)
		return (0);
	wid = ft_strlen(s[0]);
	j = 0;
	while (s[j])
	{
		if (ft_strlen(s[j]) != wid)
			return (0);
		j++;
	}
	return (wid);
}

void	count_obj(t_game *game, int i, int j)
{
	if (game->arr_map[j][i] == 'P')
	{
		game->player_x = i;
		game->player_y = j;
		game->player_len++;
	}
	if (game->arr_map[j][i] == 'A')
	{
		game->emy_x = i;
		game->emy_y = j;
		game->emy_len++;
	}
	if (game->arr_map[j][i] == 'C')
		game->col_len++;
	if (game->arr_map[j][i] == 'E')
		game->exit_len++;
}

int	check(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->arr_map[j])
	{
		i = 0;
		while (game->arr_map[j][i])
		{
			if ((j == 0 || i == 0 || j == game->map_heg - 1 || \
				i == game->map_wid - 1) && game->arr_map[j][i] != '1')
				return (1);
			if (game->arr_map[j][i] != '1' && game->arr_map[j][i] != '0' && \
				game->arr_map[j][i] != 'E' && game->arr_map[j][i] != 'A' && \
				game->arr_map[j][i] != 'C' && game->arr_map[j][i] != 'P')
				return (1);
			count_obj(game, i, j);
			i++;
		}
		j++;
	}
	if (game->player_len != 1 || game->col_len < 1 || \
		game->exit_len != 1 || game->emy_len > 1)
		return (1);
	return (0);
}

void	map_check(t_game *game, char *map)
{
	if (*map == '\0')
		exit_map_error(game);
	game->arr_map = ft_split(map, '\n');
	game->map = ft_split(map, '\n');
	game->map_wid = check_wid_same(game->arr_map);
	if (game->map_wid < 1 || game->map_heg < 2)
		exit_map_error(game);
	if (check(game))
	{
		ft_printf("check(game)\n");
		exit_map_error(game);
	}
	flood_fill(game);
}

void	map_init(t_game *game)
{
	int		fd;
	char	*map;
	char	*map_temp;
	char	*readd;

	map = NULL;
	fd = open(game->path_map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Map path not found\n");
		exit(0);
	}
	while ((readd = get_next_line(fd)))
	{
		if (!map)
			map = ft_strdup(readd);
		else
		{
			map_temp = ft_strjoin(map, readd);
			free(map);
			map = map_temp;
		}
		game->map_heg++;
		free(readd);
	}
	close(fd);
	map_check(game, map);
	if (map)
		free(map);
}
