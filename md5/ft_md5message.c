/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 01:16:06 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/25 21:40:51 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_md5.h"

extern char		*g_optarg;

int			ft_isfile(const char *name)
{
	DIR *directory;

	directory = opendir(name);
	if (directory != NULL)
	{
		closedir(directory);
		return (0);
	}
	if (errno == ENOTDIR)
		return (1);
	return (-1);
}

char		*ft_md5read_file(int fd, t_md5 *main)
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

uint8_t		*ft_md5get_bits(t_md5 *main, int *new_len)
{
	uint8_t		*msg;
	uint64_t	bits_len;

	*new_len = main->input_len * 8 + 1;
	while (*new_len % 512 != 448)
		(*new_len)++;
	*new_len /= 8;
	msg = ft_memalloc(*new_len + 64);
	ft_memcpy(msg, main->message, main->input_len);
	msg[main->input_len] = 128;
	bits_len = 8 * main->input_len;
	ft_memcpy(msg + *new_len, &bits_len, 8);
	return (msg);
}

char		*ft_md5get_mff(char *filename, t_md5 *main)
{
	int		fd;
	char	*message;

	if (!filename)
		return (ft_md5read_file(0, main));
	if (!ft_isfile(filename))
	{
		ft_printf("%s %s: Is a directory\n", NAME, filename);
		return (NULL);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%s %s: no such file or directory\n", NAME, filename);
		return (NULL);
	}
	message = ft_md5read_file(fd, main);
	close(fd);
	return (message);
}
