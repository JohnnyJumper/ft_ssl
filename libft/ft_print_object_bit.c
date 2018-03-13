/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_object_bit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 03:11:35 by jtahirov          #+#    #+#             */
/*   Updated: 2017/12/13 17:23:24 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_object_bit_print(size_t const size, void const *const ptr)
{
	unsigned char	*b;
	unsigned char	byte;
	size_t			i;
	int				j;

	b = (unsigned char*)ptr;
	i = -1;
	while (++i < size)
	{
		j = 8;
		while (--j >= 0)
		{
			byte = (b[i] >> j) & 1;
			ft_putnbr(byte);
		}
		ft_putchar(' ');
	}
	ft_putchar('\n');
}
