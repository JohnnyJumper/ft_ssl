/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 21:52:25 by jtahirov          #+#    #+#             */
/*   Updated: 2017/12/30 15:55:06 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/des.h"

int				ft_check_bit(unsigned long block, int num, int size, bool flag)
{
	unsigned long	resut;
	unsigned long	res;
	size_t			times;

	resut = 0x01;
	times = (size == 56 || size == 64) ? 64 - num : 56 - num;
	times = (flag) ? 32 - num : times;
	resut = resut << times;
	res = block & resut;
	return (res != 0);
}

static void		ft_create_subkeys(unsigned long *subkeys, t_dinput *input)
{
	int		counter;

	counter = -1;
	while (++counter < 16)
		subkeys[counter] = ft_des_subkey(input);
}

unsigned long	ft_get_subkey(t_dinput *input, bool rev)
{
	static unsigned long		*subkeys;
	static int					counter = -1;
	unsigned long				result;

	if (counter == -1)
		counter = (rev) ? 15 : 0;
	if (!subkeys)
	{
		subkeys = (unsigned long *)ft_memalloc(sizeof(unsigned long) * 16);
		ft_create_subkeys(subkeys, input);
	}
	result = subkeys[counter];
	counter += (rev) ? -1 : 1;
	counter = (counter > 15) ? -1 : counter;
	return (result);
}
