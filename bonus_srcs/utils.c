/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:44:11 by acarle-m          #+#    #+#             */
/*   Updated: 2022/02/01 13:24:06 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	ft_fractol(t_instance *game, int x, int y)
{
	if (game->type == 1)
		return (mandelbrot_set(game, x, y));
	if (game->type == 2)
		return (julia_set(game, x, y));
	if (game->type == 3)
		return (bonus_set(game, x, y));
	return (0);
}

void	zoom_in(t_instance *game, int x, int y)
{
	mlx_clear_window(game->mlx, game->win);
	fprintf(stdout, "x : %i, y : %i", x, y);
	game->x_off = x - game->x_off;
	game->y_off = y - game->y_off;
	fprintf(stdout, "x_off : %i, y_off : %i", game->x_off, game->y_off);
	game->zoom_level *= 1.07;
	put_set_to_image(game);
}

void	zoom_out(t_instance *game, int x, int y)
{
	mlx_clear_window(game->mlx, game->win);
	printf("x : %i, y : %i", x, y);
	game->zoom_level /= 1.07;
	put_set_to_image(game);
}

int	get_type(const char *s, t_instance *game)
{
	if (ft_strncmp("-m", s, 2) == 0 || ft_strncmp("--mandelbrot", s, 12) == 0)
	{
		game->type = 1;
		return (game->type);
	}
	if (ft_strncmp("-j", s, 2) == 0 || ft_strncmp("--julia", s, 7) == 0)
	{
		game->type = 2;
		return (game->type);
	}
	if (ft_strncmp("-b", s, 2) == 0 || ft_strncmp("--bonus", s, 7) == 0)
	{
		game->type = 3;
		return (game->type);
	}
	return (0);
}

void	pixel_to_image(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
