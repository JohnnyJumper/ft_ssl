/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse64.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:50:24 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/03 17:59:02 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/base64.h"

void		ft_parse_base64_flags(t_binput *input, int argc, char **flags)
{
	char	*command;
	int		counter;

	counter = 0;
	while (--argc)
	{
		command = flags[counter++];
		if (*command == '-')
			command++;
		if (*command == 'd' && !(input->flag.encode = false))
			input->flag.decode = true;
		else if (*command == 'i' && (argc--))
		{
			input->flag.input = true;
			input->input_filename = flags[counter++];
		}
		else if (*command == 'o' && (argc--))
		{
			input->flag.output = true;
			input->output_filename = flags[counter++];
		}
	}
}

static char	*parse_via_get_next_line(int fd_input)
{
	char *message;
	char *tmp;
	char *data;

	message = ft_strnew(0);
	while (ft_get_next_line(fd_input, &data))
	{
		tmp = message;
		message = ft_strjoin(message, data);
		if (tmp)
			ft_strdel(&tmp);
	}
	return (message);
}

static char	*parse_via_read(int fd_input, t_binput *input)
{
	char	*message;
	char	buf[BUFF_SIZE + 1];
	int		i;
	char	*tmp;

	message = ft_strnew(0);
	ft_bzero(buf, BUFF_SIZE);
	while ((i = read(fd_input, &buf, BUFF_SIZE)))
	{
		tmp = message;
		message = ft_strnew(input->len + i + 1);
		ft_memcpy(message, tmp, input->len);
		ft_memcpy(message + input->len, buf, i);
		input->len += i;
		ft_bzero(buf, i);
		ft_strdel(&tmp);
	}
	return (message);
}

char		*ft_base64_message(int fd_input, t_binput *input)
{
	char	*message;

	if (input->flag.encode)
		message = parse_via_read(fd_input, input);
	else
		message = parse_via_get_next_line(fd_input);
	return (message);
}
