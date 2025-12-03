#include "../includes/so_long.h"

int	ft_close_game(t_game *game)
{
	ft_free_all_memory(game);
	exit (EXIT_SUCCESS);
	return (0);
}
