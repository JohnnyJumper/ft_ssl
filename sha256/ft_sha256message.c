/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:24:14 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/24 00:25:29 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_sha256.h"

extern char			*g_optarg;

char		*ft_sha256read_file(int fd, t_sha256 *main)
{
	char	*result;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];
	int		ret;

	ft_bzero(buf, BUFF_SIZE);
	result = ft_strnew(0);
	main->input_len = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		tmp = result;
		result = ft_strnew(main->input_len + ret + 1);
		ft_memcpy(result, tmp, main->input_len);
		ft_memcpy(result + main->input_len, buf, ret);
		main->input_len += ret;
		ft_strdel(&tmp);
		ft_bzero(buf, BUFF_SIZE);
	}
	return (result);
}

uint8_t		*ft_sha256get_bits(t_sha256 *main, int *new_len)
{
	uint8_t			*msg;
	unsigned int	bits_len;

	*new_len = main->input_len * 8 + 1;
	while (*new_len % 512 != 448)
		(*new_len)++;
	*new_len /= 8;
	msg = ft_memalloc(*new_len + 64 + 1);
	ft_memcpy(msg, main->message, main->input_len);
	msg[main->input_len] = 128;
	bits_len = 8 * main->input_len;
	ft_memcpy(msg + *new_len, &bits_len, 4);
	return (msg);
}

char		*ft_sha256get_mff(char *filename, t_sha256 *main)
{
	int		fd;
	char	*message;

	if (!filename)
		return (ft_sha256read_file(0, main));
	if (!ft_isfile(filename))
	{
		ft_printf("%s %s: Is a directory\n", NAMES, filename);
		return (NULL);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%s %s: no such file or directory\n", NAMES, filename);
		return (NULL);
	}
	message = ft_sha256read_file(fd, main);
	close(fd);
	return (message);
}
