/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 11:54:05 by acarle-m          #+#    #+#             */
/*   Updated: 2022/01/29 12:01:33 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_instance	*ft_newinstance(void)
{
	t_instance	*game;

	game = (t_instance *) malloc(sizeof(t_instance));
	if (!game)
		return (NULL);
	game->mlx = NULL;
	game->win = NULL;
	game->type = 1;
	game->height = 800;
	game->width = 600;
	game->y_off = 0;
	game->x_off = 0;
	game->zoom_level = 1;
	game->img = ft_newimg();
	return (game);
}

t_img	*ft_newimg(void)
{
	t_img	*img;

	img = (t_img *) malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
	return (img);
}