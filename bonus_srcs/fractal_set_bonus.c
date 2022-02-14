/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:44:14 by acarle-m          #+#    #+#             */
/*   Updated: 2022/02/14 11:36:54 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol_bonus.h>

int	julia_set(t_instance *game, int x, int y)
{
	t_double	nb;
	int			iteration;

	nb.xscale = (game->width_ratio / game->zoom_level
			* (x - game->x_off) / game->width);
	nb.yscale = (game->height_ratio / game->zoom_level
			* (y - game->y_off) / game->height);
	nb.x0 = game->julia_x;
	nb.y0 = game->julia_y;
	iteration = 0;
	while (((nb.xscale * nb.xscale + nb.yscale * nb.yscale) < 4)
		&& (iteration < MAX_ITERATION))
	{
		nb.tmp = nb.xscale * nb.xscale - nb.yscale * nb.yscale;
		nb.yscale = 2 * nb.xscale * nb.yscale + nb.y0;
		nb.xscale = nb.tmp + nb.x0;
		iteration++;
	}
	if (iteration == MAX_ITERATION)
		return (0);
	return (iteration);
}

int	mandelbrot_set(t_instance *game, int x, int y)
{
	t_double	nb;
	int			iteration;

	nb.xscale = (game->width_ratio / game->zoom_level
			* (x - game->x_off) / game->width);
	nb.yscale = (game->height_ratio / game->zoom_level
			* (y - game->y_off) / game->height);
	if ((nb.xscale > -0.5 && nb.xscale < 0.2)
		&& (nb.yscale > -0.45 && nb.yscale < 0.45))
		return (0);
	nb.x0 = 0;
	nb.y0 = 0;
	iteration = 0;
	while (((nb.x0 * nb.x0 + nb.y0 * nb.y0) < 4) && (iteration < MAX_ITERATION))
	{
		nb.tmp = nb.x0 * nb.x0 - nb.y0 * nb.y0 + nb.xscale;
		nb.y0 = 2 * nb.x0 * nb.y0 + nb.yscale;
		nb.x0 = nb.tmp;
		iteration++;
	}
	if (iteration == MAX_ITERATION)
		return (0);
	return (iteration);
}

int	bonus_set(t_instance *game, int x, int y)
{
	t_double	nb;
//z^3-1 
float2 Function (float2 z)
{
	return cpow(z, 3) - float2(1, 0); //cpow is an exponential function for complex numbers
}

//3*z^2
float2 Derivative (float2 z)
{
	return 3 * cmul(z, z); //cmul is a function that handles multiplication of complex numbers
}

It is now just a matter of implementing the Newton method using the given functions.

float2 roots[3] = //Roots (solutions) of the polynomial
{
	float2(1, 0), 
	float2(-.5, sqrt(3)/2), 
	float2(-.5, -sqrt(3)/2)
};
	
color colors[3] =  //Assign a color for each root
{
    red,
    green,
    blue
}

For each pixel (x, y) on the target, do:
{
	zx = scaled x coordinate of pixel (scaled to lie in the Mandelbrot X scale (-2.5, 1))
    zy = scaled y coordinate of pixel (scaled to lie in the Mandelbrot Y scale (-1, 1))

    float2 z = float2(zx, zy); //z is originally set to the pixel coordinates

	for (int iteration = 0;
	     iteration < maxIteration;
	     iteration++;)
	{
		z -= cdiv(Function(z), Derivative(z)); //cdiv is a function for dividing complex numbers

        float tolerance = 0.000001;
        
		for (int i = 0; i < roots.Length; i++)
		{
		    float2 difference = z - roots[i];
		    
			//If the current iteration is close enough to a root, color the pixel.
			if (abs(difference.x) < tolerance && abs (difference.y) < tolerance)
			{
				return colors[i]; //Return the color corresponding to the root
			}
		}
		
    }
    
    return black; //If no solution is found
}

}