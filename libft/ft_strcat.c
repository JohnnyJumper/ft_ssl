/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 21:44:04 by jtahirov          #+#    #+#             */
/*   Updated: 2017/12/15 00:57:11 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *des;

	des = dest;
	while (*des != '\0')
		des++;
	while (*src != '\0')
	{
		*(des) = *(src);
		src++;
		des++;
	}
	*(des) = '\0';
	return (dest);
}
