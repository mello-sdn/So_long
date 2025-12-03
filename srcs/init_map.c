#include "../includes/so_long.h"

void	ft_check_arguments(int argc, char **argv, t_game *game)
{
	int	filename_len;

	game->map_alloc = false;
	if (argc < 2)
		ft_error("Error\nThe map is missing!", game);
	if (argc > 2)
		ft_error("Error\nToo many arguments!",
			game);
	filename_len = ft_strlen_v2(argv[1]);
	if (!ft_strnstr(&argv[1][filename_len - 4], ".ber", 4))
		ft_error("Error\nWrong extension file. It should be '.ber'", game);
}

void	ft_init_map(char *filename, t_game *game)
{
	int		map_fd;
	char	*map;

     map = NULL;
	map_fd = open(filename, O_RDONLY);
	if (map_fd < 0)
		ft_error("Error\nMap can't be opened. Does your map file exist?",
			game);
    if (game->map_alloc)
		ft_free_map(game);
	ft_get_map(game, &map, map_fd);
	close(map_fd);
	is_empty_line(game, &map);
	game->map.full = ft_split(map, '\n');
	free(map);
	if (!game->map.full)
		ft_error("Error\nFailed to allocate full map with split function",
			game);
	game->map_alloc = true;
}

void	ft_get_map(t_game *game, char **map, int map_fd)
{
	char	*tmp;
	char	*line;
	int		i;

	i = 0;
	*map = ft_strdup("");
	while (1)
	{
		line = get_next_line(map_fd);
		if (!line)
			break ;
		tmp = *map;
		*map = ft_strjoin(*map, line);
		free(tmp);
		if (!*map)
			ft_error("Error\nMemory allocation for line failed.", game);
		free(line);
		i++;
	}
}
