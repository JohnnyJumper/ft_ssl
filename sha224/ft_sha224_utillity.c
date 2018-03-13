/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha224_utillity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 23:57:07 by jtahirov          #+#    #+#             */
/*   Updated: 2018/02/01 22:08:15 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_sha224.h"

extern char		*g_optarg;

void	ft_sha224init_parts(t_sha224 *main)
{
	main->part.a = INIT_SHA224_A;
	main->part.b = INIT_SHA224_B;
	main->part.c = INIT_SHA224_C;
	main->part.d = INIT_SHA224_D;
	main->part.e = INIT_SHA224_F;
	main->part.f = INIT_SHA224_F;
	main->part.g = INIT_SHA224_G;
	main->part.h = INIT_SHA224_H;
}

int		ft_sha224handle_file(t_sha224 *main, char *filename, bool *flag)
{
	main->flag.file = true;
	*flag = true;
	main->message = ft_sha224get_mff(filename, main);
	main->filename = filename;
	return (1);
}

int		ft_sha224handle_string(t_sha224 *main)
{
	main->flag.string = true;
	main->message = g_optarg;
	main->input_len = ft_strlen(g_optarg);
	return (1);
}

int		ft_sha224handle_input(t_sha224 *main)
{
	main->flag.in = true;
	main->message = ft_sha224read_file(0, main);
	ft_printf("%s", main->message);
	return (1);
}

void	ft_sha224algo_final_helper(t_sha224 *main)
{
	main->bitlen += main->data_len * 8;
	main->data[63] = main->bitlen;
	main->data[62] = main->bitlen >> 8;
	main->data[61] = main->bitlen >> 16;
	main->data[60] = main->bitlen >> 24;
	main->data[59] = main->bitlen >> 32;
	main->data[58] = main->bitlen >> 40;
	main->data[57] = main->bitlen >> 48;
	main->data[56] = main->bitlen >> 56;
}
