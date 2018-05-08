/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_encodev2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:21:07 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/08 15:26:54 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/base64.h"

static t_uchar g_charset[] =
{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};

static char	*ft_strfjoin(char *s1, char *s2)
{
	char *new_str;

	new_str = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (new_str);
}

static void	pad_0(t_uchar *cipher, t_uchar *message)
{
	cipher[0] = g_charset[*message >> 2];
	cipher[1] = g_charset[((*message & 0x03) << 4) + (*(message + 1) >> 4)];
	cipher[2] = g_charset[((*(message + 1) & 0x0F) << 2)
	+ (*(message + 2) >> 6)];
	cipher[3] = g_charset[*(message + 2) & 0x3F];
}

static void	pad_1(t_uchar *cipher, t_uchar *message)
{
	cipher[0] = g_charset[*message >> 2];
	cipher[1] = g_charset[((*message & 0x03) << 4) + (*(message + 1) >> 4)];
	cipher[2] = g_charset[(*(message + 1) & 0x0F) << 2];
	cipher[3] = '=';
}

static void	pad_2(t_uchar *cipher, t_uchar *message)
{
	cipher[0] = g_charset[*message >> 2];
	cipher[1] = g_charset[(*message & 0x03) << 4];
	cipher[2] = '=';
	cipher[3] = '=';
}

t_uchar	*base64_encodeV2(t_uchar *message, int *len)
{
	int		i;
	t_uchar	*cipher;

	i = 0;
	cipher = (t_uchar *)ft_strnew(4 * (*len / 3 + ((*len % 3) ? 1 : 0)));
	while (i < *len / 3)
	{
		pad_0(cipher + i * 4, message + i * 3);
		i++;
	}
	if (*len % 3 == 2)
		pad_1(cipher + i * 4, message + i * 3);
	else if (*len % 3 == 1)
		pad_2(cipher + i * 4, message + i * 3);
	if (*len)
	{
		cipher = (t_uchar *)ft_strfjoin((char *)cipher, "\n");
		*len = 4 * (*len / 3 + ((*len % 3) ? 1 : 0)) + 1;
	}
	return (cipher);
}