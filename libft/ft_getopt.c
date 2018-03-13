/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 01:27:12 by jtahirov          #+#    #+#             */
/*   Updated: 2018/02/02 18:16:22 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*g_optarg;
int			g_optind = 1;
int			g_optopt;
int			g_optreset;

static int		ft_check_colon(
		char *found, int argc, char *const argv[], char **left)
{
	if (*(found + 1) != ':')
		return (0);
	if (**left == '\0')
	{
		if (g_optind >= argc)
		{
			ft_printf("%s: option requires an argument -- %c\n",
					argv[0], *found);
			return (1);
		}
		g_optarg = argv[g_optind++];
		return (0);
	}
	g_optarg = *left;
	*left = NULL;
	return (0);
}

static void		ft_reset(void)
{
	g_optind = 1;
	g_optarg = NULL;
	g_optreset = 0;
	g_optopt = 0;
}

static char		ft_handle_left(
		char **left, char *const argv[], const char *optstr)
{
	*left = argv[g_optind++];
	if (**left == '-')
		*left += 1;
	else
	{
		g_optarg = argv[(g_optind - 1)];
		*left = NULL;
		return ((*optstr == ':') ? (int)':' : (int)'?');
	}
	return ('-');
}

int				ft_getopt(int argc, char *const argv[], const char *optstr)
{
	static	char	*left = NULL;
	char			g_optopt;
	char			*found;
	char			check;

	if (g_optreset == 1)
		ft_reset();
	if (argc <= g_optind && !left)
		return (-1);
	if (!left)
		if ((check = ft_handle_left(&left, argv, optstr)) == '-' ? 0 : 1)
			return (check);
	g_optopt = *left++;
	if (!(found = ft_strchr(optstr, g_optopt)) || g_optopt == ':')
	{
		ft_printf("%s: illegal option -- %c\n", argv[0], g_optopt);
		return ((int)'?');
	}
	if (ft_check_colon(found, argc, argv, &left))
		return ((int)'?');
	if (left && *left == '\0')
		left = NULL;
	return ((int)*found);
}
