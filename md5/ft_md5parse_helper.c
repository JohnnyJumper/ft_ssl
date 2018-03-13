/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5parse_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 01:13:32 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/25 20:14:54 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_md5.h"

extern char		*g_optarg;

int		ft_md5handle_file(t_md5 *main, char *filename, bool *flag)
{
	main->flag.file = true;
	*flag = true;
	main->message = ft_md5get_mff(filename, main);
	main->filename = filename;
	return (1);
}

int		ft_md5handle_string(t_md5 *main)
{
	main->flag.string = true;
	main->message = g_optarg;
	main->input_len = ft_strlen(g_optarg);
	return (1);
}

int		ft_md5handle_input(t_md5 *main)
{
	main->flag.in = true;
	main->message = ft_md5read_file(0, main);
	return (1);
}

void	ft_usage(void)
{
	ft_printf("usage: ./ft_ssl md5 [-prq] [-s string] [files ...]\n");
	exit(1);
}
