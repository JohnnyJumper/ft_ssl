/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_decode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:17:03 by jtahirov          #+#    #+#             */
/*   Updated: 2017/12/30 15:36:23 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/base64.h"

char			*ft_base64_hdecode(int fd_input, t_binput *input)
{
	char	*message;
	char	*tmp;
	char	*res;

	message = ft_base64_message(fd_input, input);
	tmp = message;
	message = ft_strtrim(message);
	ft_strdel(&tmp);
	init_g_table();
	res = ft_base64_decode(message, input);
	return (res);
}

static void		ft_base64_decode_helper(char **mes, char **r)
{
	char	*message;
	char	*res;

	res = *r;
	message = *mes;
	if (message[0] == '\n')
		message++;
	if (message[2] == '=' && message[3] == '=')
		*res++ = ((ft_base_s(message[0]) << 2) | (ft_base_s(message[1]) >> 4));
	else if (message[3] == '=')
	{
		*res++ = ((ft_base_s(message[0]) << 2) | (ft_base_s(message[1]) >> 4));
		*res++ = ((ft_base_s(message[1]) << 4) | (ft_base_s(message[2]) >> 2));
	}
	else
		ft_get_chrbase64((unsigned char **)&message, &res);
}

char			*ft_base64_decode(char *message, t_binput *input)
{
	int		n;
	char	*res;
	char	*start;

	n = ft_strlen(message);
	input->len = (ft_strlen(message) / 4) * 3;
	res = ft_strnew(input->len);
	start = res;
	if (!g_table)
		init_g_table();
	while (n > 4)
	{
		ft_get_chrbase64((unsigned char **)&message, &res);
		n -= 4;
	}
	ft_base64_decode_helper(&message, &res);
	return (start);
}
