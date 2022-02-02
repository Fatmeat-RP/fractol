/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:10:32 by acarle-m          #+#    #+#             */
/*   Updated: 2022/02/02 21:10:38 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_instance	*ft_newinstance(void)
{
	t_instance	*game;

	game = malloc(sizeof(t_instance));
	if (!game)
	{
		printf("couldn't malloc!!");
		exit (EXIT_FAILURE);
	}
	game->width = 1920;
	game->height = 1080;
	game->x_off = game->width / 2;
	game->y_off = game->height / 2;
	game->zoom_level = 1;
	game->type = 1;
	game->resratio = game->height / game->width;
	game->julia_y = 0.5;
	game->julia_x = 0.5;
	return (game);
}
