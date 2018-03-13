/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 20:24:31 by jtahirov          #+#    #+#             */
/*   Updated: 2018/02/01 22:04:37 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_ssl.h"

void		init_progs(t_prog *progs)
{
	progs[0] = &ft_ssl_help;
	progs[1] = &ft_base64;
	progs[2] = &ft_des;
	progs[3] = &ft_md5;
	progs[4] = &ft_sha256;
	progs[5] = &ft_sha224;
}

t_prog		get_function(char *command, bool *cbc_mode)
{
	static t_prog	*progs;

	if (!progs)
	{
		progs = ft_memalloc(sizeof(*progs) * 5);
		if (progs)
			init_progs(progs);
	}
	if (!ft_strcmp(command, "base64"))
		return (progs[1]);
	if (!ft_strcmp(command, "des") || !ft_strcmp(command, "des-ecb"))
		return (progs[2]);
	if (!ft_strcmp(command, "des-cbc") && (*cbc_mode = true))
		return (progs[2]);
	if (!ft_strcmp(command, "md5"))
		return (progs[3]);
	if (!ft_strcmp(command, "sha256"))
		return (progs[4]);
	if (!ft_strcmp(command, "sha224"))
		return (progs[5]);
	return (progs[0]);
}

int			main(int argc, char **argv)
{
	t_prog	func;
	bool	cbc_mode;

	check_argc(argc);
	func = get_function(argv[1], &cbc_mode);
	func(argc - 1, argv + 2, cbc_mode);
	return (0);
}
