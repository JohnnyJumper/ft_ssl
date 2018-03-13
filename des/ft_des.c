/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 20:00:52 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/19 00:11:53 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/des.h"

void		ft_des_to_base64(t_dinput *input, char **res)
{
	t_binput	*input_base;

	input_base = create_bstruct(input);
	*res = (input->flag.encode) ? ft_base64_encode(*res, input_base) :
		ft_base64_decode(*res, input_base);
	input->len = input_base->len;
}

static int	ft_validate_padding(unsigned char *end_of_message, int times)
{
	unsigned char	value;

	value = times;
	while (times--)
	{
		if (*end_of_message-- != value)
			return (0);
	}
	return (1);
}

char		*ft_remove_pad(unsigned char *message)
{
	unsigned char	*end;
	int				times;

	end = (unsigned char *)ft_strchr((char *)message, '\0');
	times = *(--end);
	if (ft_validate_padding(end, times))
	{
		while (times--)
			*end-- = '\0';
	}
	return ((char *)message);
}

void		ft_des_get_key_stdin(t_dinput *input)
{
	unsigned char	*rawkey;
	unsigned char	*confirmation;
	unsigned char	*iv;

	ft_printf("enter des-ecb encryption password: ");
	ft_get_next_line(0, (char **)&rawkey);
	ft_printf("Verifying - enter des-ecb encryption password: ");
	ft_get_next_line(0, (char **)&confirmation);
	if (ft_strcmp((char *)confirmation, (char *)rawkey))
	{
		ft_printf("Verify failure\nbad password read\n");
		exit(255);
	}
	input->flag.key = true;
	input->key = ft_des_getkey(rawkey);
	if (!input->flag.cbc_mode)
		return ;
	ft_printf("enter initial vector: ");
	ft_get_next_line(0, (char **)&iv);
	ft_des_getiv(iv, input);
	input->flag.iv = true;
}

void		ft_des(int argc, char **argv, bool cbc_mode)
{
	t_dinput	*input;
	int			fd_input;
	int			fd_output;
	char		*res;

	fd_input = 0;
	fd_output = 1;
	input = create_dstruct(cbc_mode);
	ft_parse_des_flags(input, argc, argv);
	if (!input->flag.key)
		ft_des_get_key_stdin(input);
	if (input->flag.input)
		fd_input = ft_openfile(input->input_filename, true);
	if (input->flag.output)
		fd_output = ft_openfile(input->output_filename, false);
	res = ft_des_hencode(fd_input, input);
	if (input->flag.base64 && input->flag.encode)
		ft_des_to_base64(input, &res);
	if (input->flag.decode && !input->flag.nopad)
		res = ft_remove_pad((unsigned char *)res);
	write(fd_output, res, input->len);
}
