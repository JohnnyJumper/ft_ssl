/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_encode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 02:17:05 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/03 17:59:17 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/base64.h"

char			*ft_base64_hencode(int fd_input, t_binput *input)
{
	char *mes;
	char *res;

	mes = ft_base64_message(fd_input, input);
	res = ft_base64_encode(mes, input);
	return (res);
}

static void		ft_base64_encode_final(char **res, unsigned char *mes, int n)
{
	*(*res)++ = g_table[(int)(*mes >> 2)];
	if (n == 1)
	{
		*(*res)++ = g_table[(int)((*mes & 0x03) << 4)];
		*(*res)++ = '=';
	}
	else
	{
		*(*res)++ = g_table[(int)(((*mes & 0x03) << 4) |
				(*(mes + 1) >> 4))];
		*(*res)++ = g_table[(int)((*(mes + 1) & 0x0f) << 2)];
	}
	*(*res)++ = '=';
}

char			*ft_base64_encode(char *mes, t_binput *input)
{
	int		n;
	char	*res;
	char	*start;
	int		count;

	n = input->len;
	input->len = (n % 3 == 0) ? (n * 4) / 3 : (((n / 3) + 1) * 4);
	input->len += input->len / 64;
	res = ft_strnew(input->len + 2);
	start = res;
	count = 0;
	if (!g_table)
		init_g_table();
	while (n >= 3)
	{
		ft_get_base64chr((unsigned char **)&mes, &res);
		n -= 3;
		count += 4;
		if (count % 64 == 0)
			*res++ = '\n';
	}
	if (n > 0)
		ft_base64_encode_final(&res, (unsigned char *)mes, n);
	*res = '\n';
	return (start);
}
