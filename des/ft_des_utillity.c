/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_utillity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 20:20:23 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/04 15:12:24 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/des.h"

unsigned long	permutation(int order[], int out, void *data, bool flag)
{
	unsigned long	block;
	unsigned long	permut;
	int				counter;

	block = *(unsigned long *)data;
	counter = 0;
	permut = 0;
	while (counter < out)
	{
		if (ft_check_bit(block, order[counter++], out, flag))
			permut = (permut << 1) | 0x01;
		else
			permut = (permut << 1);
	}
	return (permut);
}

t_dinput		*create_dstruct(bool cbc)
{
	t_dinput	*new;

	new = (t_dinput *)ft_memalloc(sizeof(t_dinput));
	new->init_k = 0;
	new->flag.encode = true;
	new->flag.cbc_mode = (cbc) ? true : false;
	return (new);
}

t_binput		*create_bstruct(t_dinput *input)
{
	t_binput	*new;

	new = (t_binput *)ft_memalloc(sizeof(t_binput));
	new->len = input->len;
	new->input_filename = input->input_filename;
	new->output_filename = input->output_filename;
	new->flag.input = input->flag.input;
	new->flag.decode = input->flag.decode;
	new->flag.encode = input->flag.encode;
	new->flag.output = input->flag.output;
	return (new);
}

int				ft_get_length(t_dinput *input)
{
	int				counter;

	counter = input->len;
	if (input->flag.encode)
	{
		if (counter % 8 != 0)
			counter += 8 - (counter % 8);
	}
	else if (input->flag.nopad)
	{
		if (counter % 8 != 0)
		{
			ft_printf("bad decrypt\n");
			exit(20);
		}
	}
	return (counter);
}

unsigned int	ft_des_get_sbit6(unsigned long input)
{
	static int		counter;
	unsigned long	test;
	unsigned long	resul;

	if (!counter)
		counter = 1;
	test = 0x3F;
	resul = test << (48 - counter * 6);
	resul = input & resul;
	resul = resul >> (48 - counter++ * 6);
	if (counter == 9)
		counter = 0;
	return (resul);
}
