/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:54:08 by jtahirov          #+#    #+#             */
/*   Updated: 2017/12/28 19:20:21 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	va_list		ap;
	int			res;
	char		*perc;
	int			fd;

	va_start(ap, format);
	res = 0;
	fd = 1;
	while ((perc = ft_strchr(format, '%')))
	{
		if (perc[1] == 'r')
		{
			fd = va_arg(ap, int);
			format += 3;
			continue ;
		}
		res += write(fd, format, perc - format);
		format = perc + 1;
		if (*format)
			res += parse_exec(&format, &ap, fd);
	}
	if (*format)
		res += write(fd, format, ft_strlen(format));
	va_end(ap);
	return (res);
}
