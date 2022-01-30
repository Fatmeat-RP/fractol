/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:44:38 by acarle-m          #+#    #+#             */
/*   Updated: 2022/01/29 15:55:10 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	key_handling(int keycode, t_instance *game)
{
	printf("%i", keycode);
	if (keycode == KEY_ESC)
		close_handling(game);
	if (keycode == KEY_ARROW_UP)
		game->y_off += 50;
	if (keycode == KEY_ARROW_DOWN)
		game->y_off -= 50;
	if (keycode == KEY_ARROW_LEFT)
		game->x_off += 50;
	if (keycode == KEY_ARROW_RIGHT)
		game->x_off -= 50;
	if (keycode == KEY_J)
		game->type = 2;
	if (keycode == KEY_M)
		game->type = 1;
	mlx_clear_window(game->mlx, game->win);
	put_set_to_image(game);
	return (0);
}

int	mouse_handling(int button, int x, int y, t_instance *game)
{
	if (button == LEFT_BUTTON)
		zoom_in(game, x, y);
	if (button == RIGHT_BUTTON)
		zoom_out(game, x, y);
	if (button == NORTH_SCROLL)
		zoom_in(game, x, y);
	if (button == SOUTH_SCROLL)
		zoom_out(game, x, y);
	return (0);
}

int	close_handling(t_instance *game)
{
	mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}
