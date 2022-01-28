/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:44:11 by acarle-m          #+#    #+#             */
/*   Updated: 2022/01/28 17:30:23 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_instance	*ft_fractol(t_instance *game)
{
	if (game->type == 1)
		mandelbrot_set(game);
	if (game->type == 2)
		julia_set(game);
	return (game);
}

void	zoom_in(t_instance	*game)
{
	mlx_mouse_get_pos(game->win, x, y);
	mlx_clear_window(game->mlx, game->win);
	mandelbrot_set(x, y);
}

void	zoom_out(t_instance	*game)
{

}

int	get_type(const char s*)
{
	if (ft_strcmp("julia", s, 5))
		return (2);
	if (ft_strcmp("mandelbrot", s, 10))
		return (1);
}

int	pixel_to_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!dst)
		return (-1);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}
