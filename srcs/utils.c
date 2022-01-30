/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:44:11 by acarle-m          #+#    #+#             */
/*   Updated: 2022/01/29 16:05:50 by acarle-m         ###   ########.fr       */
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
	game->x_off = x / 2;
	game->y_off = y / 2;
	game->zoom_level *= 1.05;
	put_set_to_image(game);
}

void	zoom_out(t_instance *game, int x, int y)
{
	mlx_clear_window(game->mlx, game->win);
	game->x_off = x / 2;
	game->y_off = y / 2;
	game->zoom_level /= 1.05;
	put_set_to_image(game);
}

int	get_type(const char *s)
{
	if (ft_strncmp("julia", s, 5))
		return (2);
	return (1);
}

void	pixel_to_image(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
