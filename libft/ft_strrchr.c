/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 01:18:39 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/25 18:04:57 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	chr;
	int				counter;

	chr = c;
	counter = 0;
	while (s[counter])
		counter++;
	while (counter >= 0)
	{
		if (s[counter] == chr)
			return ((char *)&s[counter]);
		counter--;
	}
	return (NULL);
}
