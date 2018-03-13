/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:43:47 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/27 19:50:55 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static void	*ft_set_long(void *b, unsigned long value_long, size_t *len)
{
	if (*len >= 8)
	{
		*(unsigned long *)b |= value_long;
		b += (*len -= 8) ? 8 : 8;
	}
	return (b);
}

static void	*ft_set_int(void *b, unsigned int value_int, size_t *len)
{
	if (*len >= 4)
	{
		*(unsigned int *)b |= value_int;
		b += (*len -= 4) ? 4 : 4;
	}
	return (b);
}

static void	*ft_set_char(void *b, char value_char, size_t *len)
{
	*(char *)b |= value_char;
	b += (*len -= 1) ? 1 : 1;
	return (b);
}

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned int	value_int;
	unsigned long	value_long;
	char			*start;
	char			*tmp;

	c = (unsigned char)c;
	start = b;
	value_int = (unsigned int)(((((c << 8) | c) << 8) | c) << 8 | c);
	value_long = (((unsigned long)value_int << 32) | (unsigned long)value_int);
	ft_bzero(b, len);
	while (len)
	{
		if (b != (tmp = ft_set_long(b, value_long, &len)))
			b = tmp;
		else if (b != (tmp = ft_set_int(b, value_int, &len)))
			b = tmp;
		else
			b = ft_set_char(b, (char)c, &len);
	}
	return (start);
}
