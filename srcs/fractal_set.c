/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:44:14 by acarle-m          #+#    #+#             */
/*   Updated: 2022/02/02 18:20:19 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	julia_set(t_instance *game, int x, int y)
{
	t_double	nb;
	int	iteration;

	nb.xscale = ((2.47 / game->zoom_level) * (x - game->x_off) / game->width);
	nb.yscale = ((2.24 / game->zoom_level) * (y - game->y_off) / game->height);
	nb.x0 = game->julia_x;
	nb.y0 = game->julia_y;
	iteration = 0;
	while (((nb.xscale * nb.xscale + nb.yscale * nb.yscale) < 4) && (iteration < MAX_ITERATION))
	{
		nb.tmp = nb.xscale * nb.xscale - nb.yscale * nb.yscale;
		nb.yscale = 2 * nb.xscale * nb.yscale + nb.y0;
		nb.xscale = nb.tmp + nb.x0;
		iteration++;
	}
	if (iteration == MAX_ITERATION)
		return(0);
	return (iteration);
}

void	put_set_to_image(t_instance *game)
{
	int	i;
	int	j;
	int	iteration;
	static int	color[6] = {0x00FA5852, 0x00DE4985, 0x00BE49DE, 0x00A952FA, 0x00F55DE6};

	i = 0;
	j = 0;
	while (i < game->width)
	{
		j = 0;
		while (j < game->height)
		{
			iteration = ft_fractol(game, i, j);
			if (iteration == 0)
				iteration = 0;
			else
				iteration = color[iteration % 5];
			pixel_to_image(&game->img, i, j, iteration);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

int	mandelbrot_set(t_instance *game, int x, int y)
{
	t_double	nb;
	int	iteration;

	nb.xscale = (4.8 / game->zoom_level * (x - game->x_off) / game->width);
	nb.yscale = (2.4 / game->zoom_level * (y - game->y_off) / game->height);
	nb.x0 = 0;
	nb.y0 = 0;
	iteration = 0;
	while (((nb.x0 * nb.x0 + nb.y0 * nb.y0) < 4) && (iteration < MAX_ITERATION))
	{
		nb.tmp = nb.x0 * nb.x0 - nb.y0 * nb.y0 + nb.xscale;
		nb.y0 = 2 * nb.x0 * nb.y0 + nb.yscale;
		nb.x0 = nb.tmp;
		iteration++;
	}
	if (iteration == MAX_ITERATION)
		return(0);
	return (iteration);
}
