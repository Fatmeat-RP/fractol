/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:44:14 by acarle-m          #+#    #+#             */
/*   Updated: 2022/01/29 15:57:47 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	julia_set(t_instance *game, int x, int y)
{
	double	yscale;
	double	xscale;
	double	x0;
	double	y0;
	double	tmp;
	int		iteration;

	xscale = (2.47 * (x - game->x_off) / game->height / game->zoom_level);
	yscale = (2.24 * (y - game->y_off) / game->width / game->zoom_level);
	x0 = xscale;
	y0 = yscale;
	iteration = 0;
	while (((xscale * xscale + yscale * yscale) < 4) && (iteration < MAX_ITERATION))
	{
		tmp = xscale * xscale - yscale * yscale;
		y0 = 2 * xscale * yscale + y0;
		x0 = tmp + x0;
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

	i = 0;
	j = 0;
	while (i < game->width)
	{
		j = 0;
		while (j < game->height)
		{
			iteration = ft_fractol(game, i , j);
			pixel_to_image(&game->img, i, j, iteration);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

int	mandelbrot_set(t_instance *game, int x, int y)
{
	double	yscale;
	double	xscale;
	double	x0;
	double	y0;
	double	tmp;
	int	iteration;

	xscale = ((2.47 * (x - game->x_off) / game->width) / game->zoom_level);
	yscale = ((2.24 * (y - game->y_off) / game->height) / game->zoom_level);
	x0 = 0;
	y0 = 0;
	iteration = 0;
	while (((x0 * x0 + y0 * y0) < 4) && (iteration < MAX_ITERATION))
	{
		tmp = x0 * x0 - y0 * y0 + xscale;
		y0 = 2 * x0 * y0 + yscale;
		x0 = tmp;
		iteration++;
	}
	if (iteration == MAX_ITERATION)
		return(0);
	return (iteration);
}
