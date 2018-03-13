/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:06:50 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/25 18:28:49 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *des;
	unsigned char *csrc;

	des = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	while (n-- > 0)
		if ((*des++ = *csrc++) == (unsigned char)c)
			return (des);
	return (NULL);
}
