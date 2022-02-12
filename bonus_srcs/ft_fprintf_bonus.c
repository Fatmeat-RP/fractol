/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 00:15:21 by acarle-m          #+#    #+#             */
/*   Updated: 2022/02/12 17:14:34 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fprintf.h>

int	get_index(char type)
{
	const char	*base;
	int			j;

	j = 0;
	base = "cspdiuxX%";
	while (base[j])
	{
		if (type == base [j])
			return (j);
		j++;
	}
	return (-1);
}

int	printage(int fd, int i, va_list ap)
{
	int		count;
	void	*pap;

	count = -1;
	if (i < 8)
		pap = va_arg(ap, void *);
	if (i == 0)
		count = ft_fputchar(fd, (char)pap);
	else if (i == 1)
		count = ft_fputstr(fd, (char *)pap);
	else if (i == 2)
		count = ft_fputp(fd, (unsigned long)pap);
	else if (i == 3 || i == 4)
		count = ft_fputint(fd, (int)pap);
	else if (i == 5)
		count = ft_fputunsigned(fd, (unsigned int)pap);
	else if (i == 6)
		count = ft_fputlhex(fd, (unsigned int)pap);
	else if (i == 7)
		count = ft_fputuhex(fd, (unsigned int)pap);
	else if (i == 8)
		count = ft_fputmod(fd);
	return (count);
}

int	ft_writeft(int fd, const char *s, va_list ap)
{
	int		count;
	int		i;
	int		index;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			index = get_index(s[i + 1]);
			if (index == -1)
				count += ft_fputchar(fd, s[i++ + 1]);
			else
			{
				count += printage(fd, index, ap);
				i++;
			}	
		}
		else
			count += ft_fputchar(fd, s[i]);
	}
	return (count);
}

int	ft_fprintf(int fd, const char *s, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, s);
	count = ft_writeft(fd, s, ap);
	if (count == -1)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	va_end(ap);
	return (count);
}
