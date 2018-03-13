/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_encode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 15:47:58 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/02 21:42:57 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/des.h"

static void		ft_get_halves(unsigned char **message, t_dinput *input)
{
	unsigned long	block;
	int				i;

	block = 0;
	i = 0;
	block = ft_get_block(*message);
	if (!input->flag.iv && input->flag.cbc_mode)
	{
		ft_printf("iv undefined\n");
		exit(25);
	}
	block = (input->flag.cbc_mode && input->flag.encode) ? \
			block ^ input->iv : block;
	input->next_iv = (input->flag.cbc_mode && input->flag.decode) ? block : 0;
	block = permutation(g_ip, 64, &block, false);
	input->left_message = (block >> 32);
	input->right_message = (block & 0xFFFFFFFF);
}

static void		helper_stuff(char **enc, unsigned char **m, \
							t_dinput *input, int *counter)
{
	*m += 8;
	*enc += 8;
	*counter += 8;
	input->left_message = 0;
	input->right_message = 0;
}

static void		check_input_len(t_dinput *input)
{
	if (input->len % 8 > 0)
	{
		if (input->flag.decode && input->flag.nopad)
		{
			ft_printf("bad decrypt\n");
			exit(20);
		}
		input->len += 8 - (input->len % 8);
	}
}

char			*ft_des_hencode(int fd_in, t_dinput *in)
{
	unsigned char	*message;
	char			*encripted;
	unsigned long	tmp;
	int				counter;

	message = ft_des_getmessage(fd_in, in);
	check_input_len(in);
	encripted = ft_strnew(in->len);
	counter = 0;
	while (counter < in->len)
	{
		ft_get_halves(&message, in);
		tmp = ft_des_algo(in);
		if (in->flag.cbc_mode && in->flag.decode)
		{
			tmp = tmp ^ in->iv;
			in->iv = in->next_iv;
		}
		ft_memcpy(encripted, &tmp, sizeof(tmp));
		encripted = ft_strrev((char *)encripted);
		helper_stuff(&encripted, &message, in, &counter);
		in->iv = (in->flag.cbc_mode && in->flag.encode) ? tmp : in->iv;
	}
	encripted -= counter;
	return ((char *)encripted);
}
