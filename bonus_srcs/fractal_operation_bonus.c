/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_operation_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:34:42 by acarle-m          #+#    #+#             */
/*   Updated: 2022/02/14 11:36:56 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol_bonus.h>

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

/*0 : x0 = width/2 y0 = height/2
when zooming on a point : x0 += (new_x0 - first_x0) * -1 * zoom_level*/
void	zoom_in(t_instance *game, int x, int y)
{
	int	i;

	i = x;
	i += y;
	mlx_clear_window(game->mlx, game->win);
	game->zoom_level += 0.15;
	put_set_to_image(game);
}

void	zoom_out(t_instance *game, int x, int y)
{
	int	i;

	i = x;
	i += y;
	mlx_clear_window(game->mlx, game->win);
	game->zoom_level -= 0.15;
	put_set_to_image(game);
}
