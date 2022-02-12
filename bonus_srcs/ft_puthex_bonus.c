/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 03:21:59 by acarle-m          #+#    #+#             */
/*   Updated: 2022/02/12 15:57:24 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fprintf.h>

int	ft_fputlhex(int fd, unsigned int p)
{
	const char		*base;
	int				k;

	k = 0;
	base = "0123456789abcdef";
	if (p >= 16)
	{
		k += ft_fputlhex(fd, (p / 16));
		p = p % 16;
	}
	k += ft_fputchar(fd, base[p]);
	return (k);
}

int	ft_fputuhex(int fd, unsigned int p)
{
	const char		*base;
	int				k;

	k = 0;
	base = "0123456789ABCDEF";
	if (p >= 16)
	{
		k += ft_fputuhex(fd, (p / 16));
		p = p % 16;
	}
	k += ft_fputchar(fd, base[p]);
	return (k);
}
