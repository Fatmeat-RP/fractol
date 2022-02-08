/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:23:56 by acarle-m          #+#    #+#             */
/*   Updated: 2022/02/08 13:50:07 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	pixel_to_image(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_set_to_image(t_instance *game)
{
	int			i;
	int			j;
	int			iteration;

	i = 0;
	j = 0;
	while (i < game->width)
	{
		j = 0;
		while (j < game->height)
		{
			iteration = ft_fractol(game, i, j);
			if (game->color == 0)
				iteration *= 8;
			else if (iteration == 0)
				iteration = 0;
			else
				iteration = game->palette[iteration % 5];
			pixel_to_image(&game->img, i, j, iteration);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
