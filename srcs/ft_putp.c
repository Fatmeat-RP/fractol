/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 03:21:54 by acarle-m          #+#    #+#             */
/*   Updated: 2022/02/12 17:15:07 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fprintf.h>

static int	ft_fputpointer(int fd, unsigned long p)
{
	const char		*base;
	unsigned long	n;
	int				k;

	k = 0;
	base = "0123456789abcdef";
	n = (unsigned long)p;
	if (n >= 16)
	{
		k += ft_fputpointer(fd, (n / 16));
		n = n % 16;
	}
	k += ft_fputchar(fd, base[n]);
	return (k);
}

int	ft_fputp(int fd, unsigned long p)
{
	int	k;

	k = 0;
	k += ft_fputchar(fd, '0');
	k += ft_fputchar(fd, 'x');
	k += ft_fputpointer(fd, p);
	return (k);
}
