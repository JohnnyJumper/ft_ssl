/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha224output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 01:24:17 by jtahirov          #+#    #+#             */
/*   Updated: 2018/02/02 18:05:58 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_sha224.h"

extern bool g_reverse;
extern bool g_quiet;

void			ft_sha224print_hash(uint8_t hash[])
{
	int idx;

	idx = 0;
	while (idx < 28)
	{
		ft_printf("%02x", hash[idx]);
		idx++;
	}
}

static void		ft_sha224print_string(uint8_t *hash, t_sha224 *main)
{
	if (g_reverse)
	{
		ft_sha224print_hash(hash);
		ft_printf(" \"%s\"\n", main->message);
	}
	else
	{
		ft_printf("SHA224 (\"%s\") = ", main->message);
		ft_sha224print_hash(hash);
		ft_putchar('\n');
	}
}

static void		ft_sha224print_file(uint8_t hash[], t_sha224 *main)
{
	if (g_reverse)
	{
		ft_sha224print_hash(hash);
		ft_printf(" %s\n", main->filename);
	}
	else
	{
		ft_printf("SHA224 (%s) = ", main->filename);
		ft_sha224print_hash(hash);
		ft_putchar('\n');
	}
}

void			ft_sha224print_output(t_sha224 *main, uint8_t hash[])
{
	if (g_quiet && !main->flag.in)
	{
		ft_sha224print_hash(hash);
		ft_putchar('\n');
		return ;
	}
	if (main->flag.file)
		ft_sha224print_file(hash, main);
	else if (main->flag.string)
		ft_sha224print_string(hash, main);
	else if (main->flag.in)
	{
		ft_printf("%s", main->message);
		ft_sha224print_hash(hash);
		ft_printf("\n");
	}
	else
	{
		ft_sha224print_hash(hash);
		ft_printf("\n");
	}
}
