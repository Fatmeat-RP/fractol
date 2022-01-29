/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:44:04 by acarle-m          #+#    #+#             */
/*   Updated: 2022/01/29 15:42:30 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_instance	*init_arg(int ac, char **av, t_instance *game)
{
	unsigned int	height;
	unsigned int	width;

	if (ac > 4)
	{
		game->type = get_type(av[1]);
		width = ft_atoi(av[2]);
		if (width < 1900 && width > 800)
			game->width = width;
		height = ft_atoi(av[3]);
		if (height < 1080 && height > 600)
			game->height = height;
	}
	else if (ac > 1)
		game->type = get_type(av[1]);
	return (game);
}

t_instance	*game_init(t_instance *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		fprintf(stderr, "Error, couldn't init mlx !");
		exit (EXIT_FAILURE);
	}
	game->win = mlx_new_window(game->mlx, game->width, game->height, "Hello world!");
	if (game->win == NULL)
	{
		fprintf(stderr, "Error, couldn't create window !");
		exit (EXIT_FAILURE);
	}
	return (game);
}

t_instance	*img_init(t_instance *game)
{
	game->img.img = mlx_new_image(game->mlx, game->width, game->height);
	if (game->img.img == NULL)
	{
		fprintf(stderr, "Error, couldn't allocate image memory !");
		exit (EXIT_FAILURE);
	}
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	if (game->img.addr == NULL)
	{
		fprintf(stderr, "Error, couldn't get img addr !");
		exit (EXIT_FAILURE);
	}
	return (game);
}

int	main(int ac, char **av)
{
	t_instance	*game;

	game = ft_newinstance();
	game = init_arg(ac, av, game);
	game = game_init(game);
	game = img_init(game);
	put_set_to_image(game);
	mlx_hook(game->win, 17, 0, close_handling, game);
	mlx_key_hook(game->win, key_handling, game);
	mlx_mouse_hook(game->win, mouse_handling, game);
	mlx_loop(game->mlx);
	return (0);
}
