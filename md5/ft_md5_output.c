/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 22:16:57 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/25 20:42:19 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"

extern bool g_reverse;
extern bool g_quiet;

void			ft_md5print_hash(uint32_t *parts)
{
	uint8_t		*ptr;

	ptr = (uint8_t *)&parts[0];
	ft_printf("%2.2x%2.2x%2.2x%2.2x", ptr[0], ptr[1], ptr[2], ptr[3]);
	ptr = (uint8_t *)&parts[1];
	ft_printf("%2.2x%2.2x%2.2x%2.2x", ptr[0], ptr[1], ptr[2], ptr[3]);
	ptr = (uint8_t *)&parts[2];
	ft_printf("%2.2x%2.2x%2.2x%2.2x", ptr[0], ptr[1], ptr[2], ptr[3]);
	ptr = (uint8_t *)&parts[3];
	ft_printf("%2.2x%2.2x%2.2x%2.2x", ptr[0], ptr[1], ptr[2], ptr[3]);
}

static void		ft_md5print_string(uint32_t *parts, t_md5 *main)
{
	if (g_reverse)
	{
		ft_md5print_hash(parts);
		ft_printf(" \"%s\"\n", main->message);
	}
	else
	{
		ft_printf("MD5 (\"%s\") = ", main->message);
		ft_md5print_hash(parts);
		ft_putchar('\n');
	}
}

static void		ft_md5print_file(uint32_t *parts, t_md5 *main)
{
	if (g_reverse)
	{
		ft_md5print_hash(parts);
		ft_printf(" %s\n", main->filename);
	}
	else
	{
		ft_printf("MD5 (%s) = ", main->filename);
		ft_md5print_hash(parts);
		ft_putchar('\n');
	}
}

void			ft_md5print_output(uint32_t *parts, t_md5 *main)
{
	if (g_quiet && !main->flag.in)
	{
		ft_md5print_hash(parts);
		ft_putchar('\n');
		return ;
	}
	if (main->flag.file)
		ft_md5print_file(parts, main);
	else if (main->flag.string)
		ft_md5print_string(parts, main);
	else if (main->flag.in)
	{
		write(1, main->message, main->input_len);
		ft_md5print_hash(parts);
		ft_printf("\n");
	}
	else
	{
		ft_md5print_hash(parts);
		ft_printf("\n");
	}
}
