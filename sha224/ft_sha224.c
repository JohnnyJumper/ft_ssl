/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha224.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:21:11 by jtahirov          #+#    #+#             */
/*   Updated: 2018/02/01 21:47:01 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_sha224.h"

extern int g_optind;

static t_sha224		*ft_sha224transform(t_sha224 *main, bool *hard_core)
{
	main->message = ft_sha224read_file(0, main);
	*hard_core = true;
	return (main);
}

void				ft_sha224(int argc, char **argv, bool cbc_mode)
{
	t_sha224	*main;
	int			argc_cpy;
	bool		flag;
	bool		hard_core;

	cbc_mode = false;
	argv--;
	argc_cpy = (argc > 1) ? argc - 1 : 1;
	flag = false;
	hard_core = false;
	while (argc_cpy - g_optind >= 0)
	{
		main = ft_sha224parse(argc, argv, &flag);
		if (!main->flag.string && !main->flag.file && !main->flag.in)
			main = ft_sha224transform(main, &hard_core);
		if (main->message)
			ft_sha224_algo_wrap(main);
		if (main->flag.file && main->message)
			ft_memdel((void **)&main->message);
		ft_memdel((void **)&main);
		if (hard_core)
			break ;
	}
}
