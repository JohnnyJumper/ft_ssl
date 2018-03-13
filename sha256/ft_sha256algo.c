/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:54:21 by jtahirov          #+#    #+#             */
/*   Updated: 2018/02/12 20:58:46 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_sha256.h"

static void		ft_sha256algo_init(t_sha256 *main)
{
	main->data_len = 0;
	main->bitlen = 0;
	main->part.a = 0x6a09e667;
	main->part.b = 0xbb67ae85;
	main->part.c = 0x3c6ef372;
	main->part.d = 0xa54ff53a;
	main->part.e = 0x510e527f;
	main->part.f = 0x9b05688c;
	main->part.g = 0x1f83d9ab;
	main->part.h = 0x5be0cd19;
}

void			ft_sha256_transform(t_sha256 *main, uint8_t data[])
{
	uint32_t	worker[10];
	uint32_t	m[64];
	int			i;

	ft_sha256get_m(m, data);
	ft_sha256assign_workers(worker, main);
	i = 0;
	while (i < 64)
	{
		worker[8] = worker[7] + EP1(worker[4]) + g_shak[i];
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
	ft_sha256assign_states(worker, main);
}

static void		ft_sha256algo_update(t_sha256 *main, uint8_t *data,
								size_t input_len)
{
	unsigned int	i;

	i = 0;
	while (i < input_len)
	{
		main->data[main->data_len++] = data[i];
		if (main->data_len == 64)
		{
			ft_sha256_transform(main, main->data);
			main->bitlen += 512;
			main->data_len = 0;
		}
		i++;
	}
}

void			ft_sha256algo_final(t_sha256 *main, uint8_t hash[])
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
		ft_sha256_transform(main, main->data);
		ft_memset(main->data, 0, 56);
	}
	ft_sha256algo_final_helper(main);
	ft_sha256_transform(main, main->data);
	ft_sha256reverse_hash(main, hash);
}

void			ft_sha256_algo_wrap(t_sha256 *main)
{
	uint8_t		hash[32];

	ft_bzero(hash, sizeof(uint8_t) * 32);
	ft_sha256algo_init(main);
	ft_sha256algo_update(main, (uint8_t *)main->message, main->input_len);
	ft_sha256algo_final(main, hash);
	ft_sha256print_output(main, hash);
}
