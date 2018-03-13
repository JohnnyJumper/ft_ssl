/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 21:48:43 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/03 18:08:09 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/des.h"

void				ft_parse_des_flags(t_dinput *input, int argc, char **flags)
{
	int		counter;

	counter = 0;
	while (--argc)
	{
		input->command = flags[counter++];
		if (*input->command == '-')
			input->command++;
		if (*input->command == 'd' && !(input->flag.encode = false))
			input->flag.decode = true;
		else if (*input->command == 'a')
			input->flag.base64 = true;
		else if ((!ft_strcmp(input->command, "iv") \
				|| (*input->command == 'v')) && (argc--))
		{
			input->flag.iv = true;
			ft_des_getiv((unsigned char *)flags[counter++], input);
		}
		else
			ft_parse_des_flags2(input, &argc, flags, &counter);
	}
}

static char			*ft_des_checkpad(char *message, t_dinput *input)
{
	int		len;

	if (input->flag.nopad && input->flag.encode)
	{
		len = ft_strlen(message);
		if (len % 8 > 0)
		{
			ft_printf("bad decrypt\n");
			exit(10);
		}
	}
	else if (input->flag.encode)
		message = ft_des_pad(message, input);
	return (message);
}

unsigned char		*ft_des_getmessage(int fd_input, t_dinput *input)
{
	int		ret;
	char	*buf;
	char	*message;
	char	*tmp;

	message = ft_strnew(0);
	buf = ft_strnew(8);
	while ((ret = read(fd_input, buf, 8)))
	{
		tmp = message;
		message = ft_strnew(input->len + ret + 1);
		ft_memcpy(message, tmp, input->len);
		ft_memcpy(message + input->len, buf, ret);
		input->len += ret;
		ft_strdel(&tmp);
		ft_bzero(buf, 8);
	}
	if (input->flag.decode)
	{
		tmp = ft_strchr(message, '\n');
		(tmp) ? *tmp = '\0' : 0;
	}
	if (input->flag.decode && input->flag.base64)
		ft_des_to_base64(input, &message);
	return ((unsigned char *)ft_des_checkpad(message, input));
}

unsigned long		ft_des_getkey(unsigned char *rawkey)
{
	unsigned long	key64;
	int				len;
	int				counter;

	key64 = 0;
	counter = 0;
	len = ft_strlen((char *)rawkey);
	while (*rawkey && counter++ < 16)
	{
		if (!HEXRANGE(*rawkey))
		{
			ft_printf("non-hex digit\ninvalid hex key value\n");
			exit(255);
		}
		key64 = key64 << 4 | ft_chrtohex(*rawkey++);
	}
	if (len < 16)
		key64 <<= (16 - len) * 4;
	return (key64);
}
