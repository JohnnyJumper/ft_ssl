/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 22:10:20 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/21 19:27:41 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	char *des;

	des = dest;
	while (*des != '\0')
		des++;
	while (*src && (nb != 0))
	{
		*des = *src;
		des++;
		src++;
		nb--;
	}
	*des = '\0';
	return (dest);
}
