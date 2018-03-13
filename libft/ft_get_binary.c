/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:44:48 by jtahirov          #+#    #+#             */
/*   Updated: 2017/12/10 21:09:00 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_binary(unsigned char octet)
{
	unsigned char	i;
	char			*res;
	int				counter;

	res = ft_strnew(8);
	counter = 0;
	i = 128;
	while (i)
	{
		if (i & octet)
			res[counter++] = '1';
		else
			res[counter++] = '0';
		i >>= 1;
	}
	return (res);
}
