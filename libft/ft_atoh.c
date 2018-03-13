/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 22:00:16 by jtahirov          #+#    #+#             */
/*   Updated: 2017/12/30 17:00:32 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_chrtohex(char x)
{
	char	*table;
	int		counter;

	table = "0123456789abcdef";
	counter = 0;
	x = (unsigned char)x;
	while (table[counter])
	{
		if (x == table[counter] || x == table[counter] - 32)
			return (counter);
		counter++;
	}
	return (-1);
}

unsigned long	ft_atoh(unsigned char *input)
{
	unsigned long	ptr;
	int				counter;
	int				i;

	counter = 0;
	i = 0;
	ptr = 0;
	while (*input && counter < 8)
	{
		ptr = ptr << 8 | (ft_chrtohex(*input) << 4) | \
			(ft_chrtohex(*(input + 1)));
		counter++;
		input += 2;
		i++;
	}
	i = -1;
	return (ptr);
}
