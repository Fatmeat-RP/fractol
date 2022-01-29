/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:44:38 by acarle-m          #+#    #+#             */
/*   Updated: 2022/01/29 12:06:55 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	key_handling(int keycode, t_instance *game)
{
	if (keycode == 53)
		close_handling(game);
	return (0);
}
/*
int	mouse_handling(int button, int x, int y, t_instance *game)
{
	if (button == 1)
		zoom_in(game);
	if (button == 2)
		zoom_out(game);
	if (button == 3)
		reset(game);
	if (button == 4)
		zoom_in(game);
	if (button == 5)
		zoom_out(game);
	return (0);
}
*/
int	close_handling(t_instance *game)
{
	mlx_destroy_image(game->mlx, game->img->img);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}
