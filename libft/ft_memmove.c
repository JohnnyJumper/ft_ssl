/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 23:40:18 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/25 18:08:59 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *psrc;
	unsigned char *pdest;

	psrc = (unsigned char *)src;
	pdest = (unsigned char *)dest;
	if (psrc == pdest)
		return (dest);
	if (psrc < pdest)
	{
		psrc += n - 1;
		pdest += n - 1;
		while (n--)
			*pdest-- = *psrc--;
	}
	else
	{
		while (n--)
			*pdest++ = *psrc++;
	}
	return (dest);
}
