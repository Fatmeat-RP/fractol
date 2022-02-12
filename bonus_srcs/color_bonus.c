/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:30:00 by acarle-m          #+#    #+#             */
/*   Updated: 2022/02/12 19:41:04 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol_bonus.h>

void	get_palette(char *s, t_instance *game)
{
	game->color = 1;
	if (ft_strncmp("pink", s, 4) == 0)
		init_palette(PINK, game);
	else if (ft_strncmp("green", s, 5) == 0)
		init_palette(GREEN, game);
	else if (ft_strncmp("red", s, 3) == 0)
		init_palette(RED, game);
	else if (ft_strncmp("brown", s, 5) == 0)
		init_palette(BROWN, game);
	else if (ft_strncmp("blue", s, 4) == 0)
		init_palette(BLUE, game);
	else
		game->color = 0;
}

int	init_palette(int color, t_instance *game)
{
	static int	pinkish[5]
		= {0x00FA5852, 0x00DE4985, 0x00BE49DE, 0x00A952FA, 0x00F55DE6};
	static int	greenish[5]
		= {0x005FF48B, 0x0033F633, 0x0010F235, 0x0042D078, 0x0000BC16};
	static int	brownish[5]
		= {0x00310b0b, 0x00471c1c, 0x00743a34, 0x00ba6b57, 0x00dda384};
	static int	redish[5]
		= {0x00d09c9c, 0x00bf7272, 0x00a72b2b, 0x00761212, 0x00440909};
	static int	blueish[5]
		= {0x0000a9db, 0x0026ebfb, 0x000003a5, 0x005e8ef4, 0x00b0e2f0};

	if (color == PINK)
		set_palette(pinkish, game);
	else if (color == GREEN)
		set_palette(greenish, game);
	else if (color == RED)
		set_palette(redish, game);
	else if (color == BROWN)
		set_palette(brownish, game);
	else if (color == BLUE)
		set_palette(blueish, game);
	return (0);
}

void	set_palette(int *palette, t_instance *game)
{
	int	i;

	i = 0;
	game->palette = malloc(5 * sizeof(int));
	if (!game->palette)
		close_handling(game);
	while (i < 5)
	{
		game->palette[i] = palette[i];
		i++;
	}
}
