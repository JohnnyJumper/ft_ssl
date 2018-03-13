/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256algo_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:27:41 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/24 01:29:46 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_sha256.h"

void	ft_sha256assign_workers(uint32_t worker[], t_sha256 *main)
{
	worker[0] = main->part.a;
	worker[1] = main->part.b;
	worker[2] = main->part.c;
	worker[3] = main->part.d;
	worker[4] = main->part.e;
	worker[5] = main->part.f;
	worker[6] = main->part.g;
	worker[7] = main->part.h;
	worker[8] = 0;
	worker[9] = 0;
}

void	ft_sha256assign_states(uint32_t worker[], t_sha256 *main)
{
	main->part.a += worker[0];
	main->part.b += worker[1];
	main->part.c += worker[2];
	main->part.d += worker[3];
	main->part.e += worker[4];
	main->part.f += worker[5];
	main->part.g += worker[6];
	main->part.h += worker[7];
}

void	ft_sha256reverse_hash(t_sha256 *main, uint8_t hash[])
{
	int i;

	i = 0;
	while (i < 4)
	{
		hash[i] = (main->part.a >> (24 - i * 8)) & 0x000000ff;
		hash[i + 4] = (main->part.b >> (24 - i * 8)) & 0x000000ff;
		hash[i + 8] = (main->part.c >> (24 - i * 8)) & 0x000000ff;
		hash[i + 12] = (main->part.d >> (24 - i * 8)) & 0x000000ff;
		hash[i + 16] = (main->part.e >> (24 - i * 8)) & 0x000000ff;
		hash[i + 20] = (main->part.f >> (24 - i * 8)) & 0x000000ff;
		hash[i + 24] = (main->part.g >> (24 - i * 8)) & 0x000000ff;
		hash[i + 28] = (main->part.h >> (24 - i * 8)) & 0x000000ff;
		i++;
	}
}

void	ft_sha256get_m(uint32_t m[], uint8_t data[])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 16)
	{
		m[i] = (data[j] << 24) | (data[j + 1] << 16) |
			(data[j + 2] << 8) | (data[j + 3]);
		j += 4;
		i++;
	}
	while (i < 64)
	{
		m[i] = SIG1(m[i - 2]) + m[i - 7] + SIG0(m[i - 15]) + m[i - 16];
		i++;
	}
}
