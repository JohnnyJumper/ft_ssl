/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 00:17:47 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/24 00:47:45 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_md5.h"

extern int		g_optind;

static t_md5	*ft_md5transform(t_md5 *main, bool *hard_core)
{
	main->message = ft_md5read_file(0, main);
	*hard_core = true;
	return (main);
}

void			ft_md5(int argc, char **argv, bool cbc_mode)
{
	t_md5	*main;
	int		argc_cpy;
	bool	flag;
	bool	hard_core;

	cbc_mode = false;
	argv--;
	argc_cpy = (argc > 1) ? argc - 1 : 1;
	flag = false;
	hard_core = false;
	while (argc_cpy - g_optind >= 0)
	{
		main = ft_md5parse(argc, argv, &flag);
		if (!main->flag.string && !main->flag.file && !main->flag.in)
			main = ft_md5transform(main, &hard_core);
		if (main->message)
			ft_md5_algo_wrap(main);
		if (main->flag.file && main->message)
			ft_memdel((void **)&main->message);
		ft_memdel((void **)&main);
		if (hard_core)
			break ;
	}
}
