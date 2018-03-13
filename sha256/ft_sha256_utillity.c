/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_utillity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 23:57:07 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/24 00:24:01 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_sha256.h"

extern char		*g_optarg;

void	ft_sha256init_parts(t_sha256 *main)
{
	main->part.a = INITS_A;
	main->part.b = INITS_B;
	main->part.c = INITS_C;
	main->part.d = INITS_D;
	main->part.e = INITS_F;
	main->part.f = INITS_F;
	main->part.g = INITS_G;
	main->part.h = INITS_H;
}

int		ft_sha256handle_file(t_sha256 *main, char *filename, bool *flag)
{
	main->flag.file = true;
	*flag = true;
	main->message = ft_sha256get_mff(filename, main);
	main->filename = filename;
	return (1);
}

int		ft_sha256handle_string(t_sha256 *main)
{
	main->flag.string = true;
	main->message = g_optarg;
	main->input_len = ft_strlen(g_optarg);
	return (1);
}

int		ft_sha256handle_input(t_sha256 *main)
{
	main->flag.in = true;
	main->message = ft_sha256read_file(0, main);
	ft_printf("%s", main->message);
	return (1);
}

void	ft_sha256algo_final_helper(t_sha256 *main)
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
