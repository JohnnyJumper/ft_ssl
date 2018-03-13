/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 01:06:11 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/25 20:05:14 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_md5.h"

void			ft_md5_algo_wrap(t_md5 *main)
{
	int		new_len;
	uint8_t	*msg;

	msg = NULL;
	msg = ft_md5get_bits(main, &new_len);
	ft_md5_algo(main, new_len, msg);
}

static void		ft_inithelper(uint32_t *parts, t_md5 *main, bool flag)
{
	if (flag == true)
	{
		parts[0] = INIT_A;
		parts[1] = INIT_B;
		parts[2] = INIT_C;
		parts[3] = INIT_D;
		return ;
	}
	main->part.a = parts[0];
	main->part.b = parts[1];
	main->part.c = parts[2];
	main->part.d = parts[3];
}

void			ft_md5_algo_main(t_md5 *main, uint32_t *word)
{
	uint32_t		i;
	uint32_t		f;
	uint32_t		g;
	uint32_t		temp;

	i = 0;
	while (i < 64)
	{
		if (i < 16)
			f = ft_md5f_function(main, &g, i);
		else if (i < 32)
			f = ft_md5g_function(main, &g, i);
		else if (i < 48)
			f = ft_md5h_function(main, &g, i);
		else
			f = ft_md5i_function(main, &g, i);
		temp = main->part.d;
		main->part.d = main->part.c;
		main->part.c = main->part.b;
		main->part.b += LEFTROTATE((main->part.a + f + g_k[i]
									+ word[g]), g_s[i]);
		main->part.a = temp;
		i++;
	}
}

void			ft_md5_algo(t_md5 *main, int new_len, uint8_t *msg)
{
	int				offset;
	uint32_t		*word;
	uint32_t		parts[4];

	offset = 0;
	ft_bzero(parts, sizeof(uint32_t) * 4);
	ft_inithelper(parts, main, true);
	while (offset < new_len)
	{
		word = (uint32_t *)(msg + offset);
		ft_inithelper(parts, main, false);
		ft_md5_algo_main(main, word);
		parts[0] = (parts[0] + main->part.a);
		parts[1] = (parts[1] + main->part.b);
		parts[2] = (parts[2] + main->part.c);
		parts[3] = (parts[3] + main->part.d);
		offset += 64;
	}
	ft_md5print_output(parts, main);
}
