/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utillity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 20:27:32 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/19 00:21:30 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_ssl.h"

void		check_argc(int argc)
{
	if (argc == 1)
	{
		ft_putstr("usage: ft_ssl command [command opts] [command args]\n");
		exit(1);
	}
}

t_binput	*create_struct(void)
{
	t_binput	*new;

	new = (t_binput *)ft_memalloc(sizeof(t_binput));
	new->len = 0;
	new->flag.encode = true;
	return (new);
}

void		ft_ssl_help(int argc, char **argv, bool cbc_mode)
{
	char *command;

	if (argc && cbc_mode)
		;
	command = argv[-1];
	ft_printf("ft_ssl:Error: \'%s\' is an invalid command.\n", command);
	ft_printf("\nStandart commands:\n");
	ft_printf("\nMessage Digest commands:\n");
	ft_printf("md5\nsha512\n");
	ft_printf("\nCipher commands:\n");
	ft_printf("base64\ndes\ndes-ecb\ndec-cbc\n");
	exit(1);
}

int			ft_openfile(char *filename, bool input)
{
	int fd;

	fd = (!input) ? open(filename, O_RDWR | O_CREAT | O_TRUNC, 0666) : \
					open(filename, O_RDWR);
	if (fd == -1)
	{
		ft_printf("%s: No such file or directory\n", filename);
		exit(2);
	}
	return (fd);
}
