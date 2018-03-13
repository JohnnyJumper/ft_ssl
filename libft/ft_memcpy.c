/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 19:38:29 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/27 19:07:25 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_cpy_long(void *dst, const void *src, size_t *n)
{
	*(long *)dst |= *(long *)src;
	dst += (*n -= 8) ? 8 : 8;
	return (dst);
}

static void		*ft_cpy_int(void *dst, const void *src, size_t *n)
{
	*(int *)dst |= *(int *)src;
	dst += (*n -= 4) ? 4 : 4;
	return (dst);
}

static void		*ft_cpy_char(void *dst, const void *src, size_t *n)
{
	*(char *)dst |= *(char *)src;
	dst += (*n -= 1) ? 1 : 1;
	return (dst);
}

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*start;

	start = dst;
	ft_bzero(dst, n);
	while (n)
	{
		if (n >= 8)
		{
			dst = ft_cpy_long(dst, src, &n);
			src += 8;
		}
		else if (n >= 4)
		{
			dst = ft_cpy_int(dst, src, &n);
			src += 4;
		}
		else
		{
			dst = ft_cpy_char(dst, src, &n);
			src++;
		}
	}
	return (start);
}
