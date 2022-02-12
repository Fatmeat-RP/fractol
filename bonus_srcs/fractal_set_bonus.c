/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:44:14 by acarle-m          #+#    #+#             */
/*   Updated: 2022/02/12 23:34:05 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol_bonus.h>

int	julia_set(t_instance *game, int x, int y)
{
	t_double	nb;
	int			iteration;

	nb.xscale = (game->width_ratio / game->zoom_level
			* (x - game->x_off) / game->width);
	nb.yscale = (game->height_ratio / game->zoom_level
			* (y - game->y_off) / game->height);
	nb.x0 = game->julia_x;
	nb.y0 = game->julia_y;
	iteration = 0;
	while (((nb.xscale * nb.xscale + nb.yscale * nb.yscale) < 4)
		&& (iteration < MAX_ITERATION))
	{
		nb.tmp = nb.xscale * nb.xscale - nb.yscale * nb.yscale;
		nb.yscale = 2 * nb.xscale * nb.yscale + nb.y0;
		nb.xscale = nb.tmp + nb.x0;
		iteration++;
	}
	if (iteration == MAX_ITERATION)
		return (0);
	return (iteration);
}

int	mandelbrot_set(t_instance *game, int x, int y)
{
	t_double	nb;
	int			iteration;

	nb.xscale = (game->width_ratio / game->zoom_level
			* (x - game->x_off) / game->width);
	nb.yscale = (game->height_ratio / game->zoom_level
			* (y - game->y_off) / game->height);
	if ((nb.xscale > -0.5 && nb.xscale < 0.2)
		&& (nb.yscale > -0.45 && nb.yscale < 0.45))
		return (0);
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
		return (0);
	return (iteration);
}

int	bonus_set(t_instance *game, int x, int y)
{
	t_double	nb;
	int			iteration;

	nb.xscale = (game->width_ratio / game->zoom_level
			* (x - game->x_off) / game->width);
	nb.yscale = (game->height_ratio / game->zoom_level
			* (y - game->y_off) / game->height);
	nb.x0 = 1;
	nb.y0 = 1;
	iteration = 0;
	while (((nb.x0 * nb.y0) < 4) && (iteration < 20))
	{
		nb.tmp = nb.xscale * 4 / nb.x0;
		nb.y0 = nb.yscale * 4 / nb.y0;
		nb.x0 = nb.tmp;
		iteration++;
	}
	if (iteration == MAX_ITERATION)
		return (0);
	return (iteration);
}