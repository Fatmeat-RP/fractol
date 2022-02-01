/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:44:04 by acarle-m          #+#    #+#             */
/*   Updated: 2022/02/01 12:04:23 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_instance	*init_arg(int ac, char **av, t_instance *game)
{

	if (ac == 2)
	{	
		if (!get_type(av[1], game))
		{
			printf("Bad set type.\n"
				"One arguments need to be read, it need to be one of the following :\n"
				"	-m --mandelbrot    draw the mandelbrot set in a new window\n"
				"	-j --julia         draw the julia set in a new window\n"
				/*"	-b --bonus         draw the bonus set in a new window\n"*/);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("One arguments need to be read, it need to be one of the following :\n"
			"	-m --mandelbrot    draw the mandelbrot set in a new window\n"
			"	-j --julia         draw the julia set in a new window\n"
			/*"	-b --bonus         draw the bonus set in a new window\n"*/);
		exit(EXIT_FAILURE);
	}
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
