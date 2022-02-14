/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:44:11 by acarle-m          #+#    #+#             */
/*   Updated: 2022/02/14 11:36:54 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol_bonus.h>

int	gcd(int a, int b)
{
	if (b == 0)
		return (a);
	return (gcd(b, (a % b)));
}

int	get_type(char **av, t_instance *game, int ac)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac)
	{
		if (ft_strncmp("-m", av[i], 3) == 0
			|| ft_strncmp("--mandelbrot", av[i], 13) == 0)
			game->type = 1;
		else if (ft_strncmp("-j", av[i], 3) == 0
			|| ft_strncmp("--julia", av[i], 8) == 0)
			game->type = 2;
		else if (ft_strncmp("-b", av[i], 3) == 0
			|| ft_strncmp("--bonus", av[i], 8) == 0)
			game->type = 3;
		if (ft_strncmp("-c", av[i], 3) == 0
			|| ft_strncmp("--color", av[i], 8) == 0)
			get_palette(av[i++ + 1], game);
		if (ft_strncmp("-o", av[i], 3) == 0
			|| ft_strncmp("--other", av[i], 8) == 0)
			get_modifier(av[i++ + 1], game);
		i++;
	}
	j = game->type;
	return (j);
}

void	aspect_ratio(t_instance *game)
{
	int	pgcd;

	pgcd = gcd(game->width, game->height);
	game->width_ratio = game->width / pgcd;
	game->height_ratio = game->height / pgcd;
}

void	get_modifier(char *s, t_instance *game)
{
	int	i;

	if (s)
	{
		i = ft_atoi(s);
		if (!i || i > 100)
			ft_fprintf(2, "	-o --other         change julia modifer"
				" (need to be an int between 1 and 100)\n");
		else
		{
			game->julia_x = (double)i / 100;
			game->julia_y = (double)i / 100;
		}
	}
}
