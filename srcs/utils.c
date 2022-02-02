/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:44:11 by acarle-m          #+#    #+#             */
/*   Updated: 2022/02/02 15:51:09 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	ft_fractol(t_instance *game, int x, int y)
{
	if (game->type == 1)
		return (mandelbrot_set(game, x, y));
	if (game->type == 2)
		return (julia_set(game, x, y));
	return (0);
}

void	zoom_in(t_instance *game, int x, int y)
{
	mlx_clear_window(game->mlx, game->win);
	printf("x :%i y :%i \n", x, y);
	game->zoom_level += 0.05;
	game->x_off += x / game->x_off * game->zoom_level;
	game->y_off += y / game->y_off * game->zoom_level;
	put_set_to_image(game);
}

void	zoom_out(t_instance *game, int x, int y)
{
	mlx_clear_window(game->mlx, game->win);
	printf("x : %i, y : %i", x, y);
	game->zoom_level -= 0.05;
	put_set_to_image(game);
}

int	get_type(char **av, t_instance *game, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (ft_strncmp("-m", av[i], 2) == 0 || ft_strncmp("--mandelbrot", av[i], 12) == 0)
		{
			game->type = 1;
			return (game->type);
		}
		if (ft_strncmp("-j", av[i], 2) == 0 || ft_strncmp("--julia", av[i], 7) == 0)
		{
			game->type = 2;
			return (game->type);
		}
		i++;
	}
	return (0);
}

void	pixel_to_image(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
