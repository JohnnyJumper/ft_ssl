/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 01:29:15 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/04 15:11:50 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/base64.h"

void			init_g_table(void)
{
	int		counter;
	char	x;

	g_table = ft_strnew(64);
	counter = 0;
	x = 'A';
	while (x <= 'Z')
		g_table[counter++] = x++;
	x = 'a';
	while (x <= 'z')
		g_table[counter++] = x++;
	x = '0';
	while (x <= '9')
		g_table[counter++] = x++;
	g_table[counter++] = '+';
	g_table[counter] = '/';
}

void			ft_get_base64chr(unsigned char **id, char **enc)
{
	unsigned int	buf;

	buf = *(*id)++ << 16;
	buf |= (**id) ? *(*id)++ << 8 : 0;
	buf |= (**id) ? *(*id)++ : 0;
	*(*enc)++ = g_table[(int)(buf >> 18)];
	buf &= 0x3FFFF;
	*(*enc)++ = g_table[(int)(buf >> 12)];
	buf &= 0xFFF;
	*(*enc)++ = g_table[(int)(buf >> 6)];
	buf &= 0x3F;
	*(*enc)++ = g_table[(int)buf];
}

unsigned char	ft_base_s(char x)
{
	int counter;

	counter = 0;
	while (counter < 64)
		if (g_table[counter++] == x)
			return (--counter);
	return (0);
}

void			ft_get_chrbase64(unsigned char **id, char **enc)
{
	unsigned int	buf;

	buf = ((ft_base_s(**id) << 2) | ft_base_s(id[0][1]) >> 4);
	*(*enc)++ = buf;
	buf = (ft_base_s(id[0][1]) << 4 | ft_base_s(id[0][2]) >> 2);
	*(*enc)++ = buf;
	buf = (ft_base_s(id[0][2]) << 6) | ft_base_s(id[0][3]);
	*(*enc)++ = buf;
	(*id) += 4;
}
