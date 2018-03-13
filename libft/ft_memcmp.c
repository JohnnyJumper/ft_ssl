/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 20:23:55 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/28 03:26:53 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_memcmp_char(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*str2;
	unsigned int	counter;

	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	counter = 0;
	while (counter < n)
	{
		if (str[counter] != str2[counter])
			return (str[counter] - str2[counter]);
		counter++;
	}
	return (0);
}

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char flag;

	flag = 0;
	while (n)
	{
		if (n >= 8)
		{
			flag += (*(long *)s1 ^ *(long *)s2) ? 1 : 0;
			if (flag)
				return (ft_memcmp_char(s1, s2, 8));
			s1 += (n -= 8) ? 8 : 8;
			s2 += 8;
		}
		else if (n >= 4)
		{
			flag += (*(int *)s1 ^ *(int *)s2) ? 1 : 0;
			if (flag)
				return (ft_memcmp_char(s1, s2, 4));
			s1 += (n -= 4) ? 4 : 4;
			s2 += 4;
		}
		else
			return (ft_memcmp_char(s1, s2, n));
	}
	return (0);
}
