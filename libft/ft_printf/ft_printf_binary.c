/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_binary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:43:21 by jtahirov          #+#    #+#             */
/*   Updated: 2017/12/30 16:59:28 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_get_object_binary(size_t size, void *data)
{
	char			*res;
	unsigned char	*b;
	int				i;
	int				j;
	int				counter;

	counter = 0;
	res = ft_strnew((8 * size) + (size - 1));
	b = (unsigned char *)data;
	i = size;
	while (--i >= 0)
	{
		j = 8;
		while (--j >= 0)
		{
			*res++ = ((b[i] >> j) & 0x01) + '0';
			counter++;
		}
		*res++ = (i - 1 >= 0) ? ' ' : '\0';
		counter++;
	}
	return (res - counter);
}

char			*ft_get_mybinary(t_arg *args, va_list *ap)
{
	char	*res;
	void	*data;
	size_t	size;

	size = va_arg(*ap, size_t);
	data = va_arg(*ap, void *);
	res = ft_get_object_binary(size, data);
	args->l = ft_strlen(res);
	return (res);
}
