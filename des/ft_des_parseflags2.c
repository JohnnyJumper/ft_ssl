/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_parseflags2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 00:56:40 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/03 18:12:37 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/des.h"

void			ft_des_getiv(unsigned char *rawiv, t_dinput *input)
{
	int		len;
	int		counter;

	input->iv = 0;
	counter = 0;
	len = ft_strlen((char *)rawiv);
	while (*rawiv && counter++ < 16)
	{
		if (!HEXRANGE(*rawiv))
		{
			ft_printf("non-hex digit\ninvalid hex key value\n");
			exit(255);
		}
		input->iv = input->iv << 4 | ft_chrtohex(*rawiv++);
	}
	if (len < 16)
		input->iv <<= (16 - len) * 4;
}

unsigned long	ft_get_block(unsigned char *message)
{
	unsigned long	tmp;
	unsigned long	block;
	int				i;

	block = 0;
	i = 0;
	tmp = 0;
	tmp = *(unsigned long *)ft_memcpy(&tmp, message, 8);
	while (i < 64)
	{
		block = block << 8 | (tmp & 0xff);
		tmp = tmp >> 8;
		i += 8;
	}
	return (block);
}

void			ft_parse_des_flags2(t_dinput *in, int *argc, char **f, int *i)
{
	if (*in->command == 'i' && ((*argc)--))
	{
		in->flag.input = true;
		in->input_filename = f[(*i)++];
	}
	else if (*in->command == 'o' && ((*argc)--))
	{
		in->flag.output = true;
		in->output_filename = f[(*i)++];
	}
	else if ((*in->command == 'k' || *in->command == 'K') && ((*argc)--))
	{
		in->flag.key = true;
		in->key = ft_des_getkey((unsigned char *)f[(*i)++]);
	}
	else if (!ft_strcmp(in->command, "nopad"))
		in->flag.nopad = true;
}

char			*ft_des_pad(char *message, t_dinput *input)
{
	char			pad_value;
	int				times;
	char			*tmp;

	pad_value = 8 - input->len % 8;
	times = pad_value;
	input->len += times;
	while (times--)
	{
		tmp = message;
		message = ft_strnjoin(message, &pad_value, 1);
		ft_strdel(&tmp);
	}
	return (message);
}
