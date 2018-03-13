/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:09:49 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/24 00:18:20 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_sha256.h"

extern char		*g_optarg;
extern int		g_optind;
extern bool		g_reverse;
extern bool		g_quiet;

static void		ft_sha256usage(void)
{
	ft_printf("usage: ./ft_ssl sha256 [-prq] [-s string] [files ...]\n");
	exit(1);
}

static void		ft_sha256parse_helper(char ch)
{
	if (ch == 'r')
		g_reverse = true;
	else if (ch == 'q')
		g_quiet = true;
	else if (ch == '?')
		ft_sha256usage();
}

t_sha256		*ft_sha256parse(int argc, char **argv, bool *last)
{
	t_sha256		*main;
	static bool		flag = false;
	char			ch;

	main = (t_sha256 *)ft_memalloc(sizeof(t_sha256));
	ft_sha256init_parts(main);
	if (flag == true)
	{
		ft_sha256handle_file(main, argv[g_optind++], &flag);
		return (main);
	}
	while ((ch = ft_getopt(argc, argv, ":prqs:")) != -1)
	{
		ft_sha256parse_helper(ch);
		if (ch == 'p' && ft_sha256handle_input(main))
			break ;
		else if (ch == 's' && ft_sha256handle_string(main))
			break ;
		else if (ch == ':' && ft_sha256handle_file(main, g_optarg, &flag))
			break ;
	}
	if (ch == -1)
		*last = true;
	return (main);
}
