/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 00:15:23 by acarle-m          #+#    #+#             */
/*   Updated: 2022/02/12 17:20:18 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_fprintf(int fd, const char *s, ...);
int	ft_fputp(int fd, unsigned long p);
int	ft_fputlhex(int fd, unsigned int p);
int	ft_fputuhex(int fd, unsigned int p);
int	ft_fputmod(int fd);
int	ft_fputstr(int fd, char *s);
int	ft_fputchar(int fd, char c);
int	ft_fputunsigned(int fd, unsigned int ui);
int	ft_fputint(int fd, int i);
int	ft_fprintf(int fd, const char *s, ...);

#endif