/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:44:11 by acarle-m          #+#    #+#             */
/*   Updated: 2022/02/09 17:42:29 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int	get_type(char **av, t_instance *game, int ac)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac)
	{
		if (ft_strncmp("-m", av[i], 2) == 0
			|| ft_strncmp("--mandelbrot", av[i], 12) == 0)
		{
			game->type = 1;
			j++;
		}
		else if (ft_strncmp("-j", av[i], 2) == 0
			|| ft_strncmp("--julia", av[i], 7) == 0)
		{
			game->type = 2;
			j++;
		}
		if (ft_strncmp("-c", av[i], 2) == 0
			|| ft_strncmp("--color", av[i], 7) == 0)
			get_palette(av[i++ + 1], game);
		i++;
	}
	return (j);
}
