/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha224algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:54:21 by jtahirov          #+#    #+#             */
/*   Updated: 2018/02/01 22:00:46 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_sha224.h"

static void		ft_sha224algo_init(t_sha224 *main)
{
	main->data_len = 0;
	main->bitlen = 0;
	main->part.a = INIT_SHA224_A;
	main->part.b = INIT_SHA224_B;
	main->part.c = INIT_SHA224_C;
	main->part.d = INIT_SHA224_D;
	main->part.e = INIT_SHA224_E;
	main->part.f = INIT_SHA224_F;
	main->part.g = INIT_SHA224_G;
	main->part.h = INIT_SHA224_H;
}

void			ft_sha224_transform(t_sha224 *main, uint8_t data[])
{
	uint32_t	worker[10];
	uint32_t	m[64];
	int			i;

	ft_sha224get_m(m, data);
	ft_sha224assign_workers(worker, main);
	i = 0;
	while (i < 64)
	{
		worker[8] = worker[7] + EP1(worker[4]) + g_sha224k[i];
		worker[8] += CH(worker[4], worker[5], worker[6]) + m[i];
		worker[9] = EP0(worker[0]) + MAJ(worker[0], worker[1], worker[2]);
		worker[7] = worker[6];
		worker[6] = worker[5];
		worker[5] = worker[4];
		worker[4] = worker[3] + worker[8];
		worker[3] = worker[2];
		worker[2] = worker[1];
		worker[1] = worker[0];
		worker[0] = worker[8] + worker[9];
		i++;
	}
	ft_sha224assign_states(worker, main);
}

static void		ft_sha224algo_update(t_sha224 *main, uint8_t *data,
								size_t input_len)
{
	unsigned int	i;

	i = 0;
	while (i < input_len)
	{
		main->data[main->data_len++] = data[i];
		if (main->data_len == 64)
		{
			ft_sha224_transform(main, main->data);
			main->bitlen += 512;
			main->data_len = 0;
		}
		i++;
	}
}

void			ft_sha224algo_final(t_sha224 *main, uint8_t hash[])
{
	unsigned int	i;

	i = main->data_len;
	if (main->data_len < 56)
	{
		main->data[i++] = 0x80;
		while (i < 56)
			main->data[i++] = 0x00;
	}
	else
	{
		main->data[i++] = 0x80;
		while (i < 64)
			main->data[i++] = 0x00;
		ft_sha224_transform(main, main->data);
		ft_memset(main->data, 0, 56);
	}
	ft_sha224algo_final_helper(main);
	ft_sha224_transform(main, main->data);
	ft_sha224reverse_hash(main, hash);
}

void			ft_sha224_algo_wrap(t_sha224 *main)
{
	uint8_t		hash[32];

	ft_bzero(hash, sizeof(uint8_t) * 32);
	ft_sha224algo_init(main);
	ft_sha224algo_update(main, (uint8_t *)main->message, main->input_len);
	ft_sha224algo_final(main, hash);
	ft_sha224print_output(main, hash);
}
