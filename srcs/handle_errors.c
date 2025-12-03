#include "../includes/so_long.h"

void	ft_free_all_memory(t_game *game)
{
	if (game)
	{
		if (game->map.full)
			ft_free_map(game);
		ft_destroy_img(game);
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		if (game->mlx_ptr)
		{
			mlx_destroy_display(game->mlx_ptr);
			free(game->mlx_ptr);
		}
		free(game);
	}
}

void	ft_destroy_img(t_game *game)
{
	if (game->wall.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
	if (game->floor.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
	if (game->collect.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->collect.xpm_ptr);
	if (game->player_front.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player_front.xpm_ptr);
	if (game->player_left.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player_left.xpm_ptr);
	if (game->player_right.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player_right.xpm_ptr);
	if (game->player_back.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player_back.xpm_ptr);
	if (game->exit.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->exit.xpm_ptr);
}

void	ft_free_map(t_game *game)
{
	int	i;

	if (!game->map.full)
		return ;
	i = 0;
	if (game->map_alloc == true)
	{
		while (game->map.full[i])
		{
			free(game->map.full[i]);
			i++;
		}
	}
	free(game->map.full);
	game->map.full = NULL;
	game->map_alloc = false;
}

void	ft_error(char *msg, t_game *game)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	ft_free_all_memory(game);
	exit(EXIT_FAILURE);
}
