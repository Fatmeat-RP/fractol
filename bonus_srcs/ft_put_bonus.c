/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 03:22:02 by acarle-m          #+#    #+#             */
/*   Updated: 2022/02/12 15:57:05 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fprintf.h>

int	ft_fputchar(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_fputstr(int fd, char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i])
		i += ft_fputchar(fd, s[i]);
	return (i);
}

int	ft_fputmod(int fd)
{
	ft_fputchar(fd, '%');
	return (1);
}

int	ft_fputunsigned(int fd, unsigned int ui)
{
	const char		*base;
	int				k;

	k = 0;
	base = "0123456789";
	if (ui >= 10)
	{
		k += ft_fputunsigned(fd, (ui / 10));
		ui = ui % 10;
	}
	k += ft_fputchar(fd, base[ui]);
	return (k);
}

int	ft_fputint(int fd, int i)
{
	int	k;

	k = 0;
	if (i < 0)
	{
		k += ft_fputchar(fd, '-');
		i *= -1;
	}
	k += ft_fputunsigned(fd, i);
	return (k);
}
