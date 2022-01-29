#include <fractol.h>

t_instance	*ft_newinstance(void)
{
	t_instance	*game;

	game = malloc(sizeof(t_instance));
	if (!game)
	{
		printf("couldn't malloc!!");
		exit (EXIT_FAILURE);
	}
	game->width = 800;
	game->height = 600;
	game->x_off = game->width / 2;
	game->y_off = game->height / 2;
	game->zoom_level = 1;
	game->type = 1;
	return (game);
}