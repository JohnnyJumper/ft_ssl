/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 01:24:17 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/24 01:33:56 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_sha256.h"

extern bool g_reverse;
extern bool g_quiet;

void			ft_sha256print_hash(uint8_t hash[])
{
	int idx;

	idx = 0;
	while (idx < 32)
	{
		ft_printf("%02x", hash[idx]);
		idx++;
	}
}

static void		ft_sha256print_string(uint8_t *hash, t_sha256 *main)
{
	if (g_reverse)
	{
		ft_sha256print_hash(hash);
		ft_printf(" \"%s\"\n", main->message);
	}
	else
	{
		ft_printf("SHA256 (\"%s\") = ", main->message);
		ft_sha256print_hash(hash);
		ft_putchar('\n');
	}
}

static void		ft_sha256print_file(uint8_t hash[], t_sha256 *main)
{
	if (g_reverse)
	{
		ft_sha256print_hash(hash);
		ft_printf(" %s\n", main->filename);
	}
	else
	{
		ft_printf("SHA256 (%s) = ", main->filename);
		ft_sha256print_hash(hash);
		ft_putchar('\n');
	}
}

void			ft_sha256print_output(t_sha256 *main, uint8_t hash[])
{
	if (g_quiet && !main->flag.in)
	{
		ft_sha256print_hash(hash);
		ft_putchar('\n');
		return ;
	}
	if (main->flag.file)
		ft_sha256print_file(hash, main);
	else if (main->flag.string)
		ft_sha256print_string(hash, main);
	else if (main->flag.in)
	{
		ft_printf("%s", main->message);
		ft_sha256print_hash(hash);
		ft_printf("\n");
	}
	else
	{
		ft_sha256print_hash(hash);
		ft_printf("\n");
	}
}
