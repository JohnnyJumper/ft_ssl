/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 00:59:35 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/29 22:05:02 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_md5.h"

extern char *g_optarg;
extern int	g_optind;
bool		g_reverse = false;
bool		g_quiet = false;

static void		ft_md5check_flag(char ch)
{
	if (ch == 'r')
		g_reverse = true;
	else if (ch == 'q')
		g_quiet = true;
	else if (ch == '?')
		ft_usage();
}

static void		ft_md5init_parts(t_md5 *main)
{
	main->part.a = INIT_A;
	main->part.b = INIT_B;
	main->part.c = INIT_C;
	main->part.d = INIT_D;
}

t_md5			*ft_md5parse(int argc, char **argv, bool *last)
{
	t_md5		*main;
	static bool	flag = false;
	char		ch;

	main = (t_md5 *)ft_memalloc(sizeof(t_md5));
	ft_md5init_parts(main);
	if (flag == true)
	{
		ft_md5handle_file(main, argv[g_optind++], &flag);
		return (main);
	}
	while ((ch = ft_getopt(argc, argv, ":prqs:")) != -1)
	{
		ft_md5check_flag(ch);
		if (ch == 'p' && ft_md5handle_input(main))
			break ;
		else if (ch == 's' && ft_md5handle_string(main))
			break ;
		else if (ch == ':' && ft_md5handle_file(main, g_optarg, &flag))
			break ;
	}
	if (ch == -1)
		*last = true;
	return (main);
}
