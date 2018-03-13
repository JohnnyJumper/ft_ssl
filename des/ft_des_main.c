/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:08:31 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/02 19:00:27 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/des.h"

unsigned long		ft_des_algo(t_dinput *input)
{
	unsigned long	tmp;
	int				counter;

	counter = 0;
	tmp = 0;
	while (counter++ < 16)
	{
		tmp = input->right_message;
		input->right_message = ft_des_encript(input);
		input->left_message = tmp;
	}
	tmp = input->right_message << 32 | input->left_message;
	tmp = permutation(g_ip2, 64, &tmp, false);
	return (tmp);
}

unsigned long		ft_des_encript(t_dinput *input)
{
	unsigned long	expanded_right;
	unsigned long	subkey;
	unsigned long	table_output;

	expanded_right = permutation(g_selection, 48, &input->right_message, true);
	subkey = ft_get_subkey(input, input->flag.decode);
	expanded_right = expanded_right ^ subkey;
	table_output = ft_des_sboxes(expanded_right);
	table_output = permutation(g_p, 32, &table_output, true);
	table_output = table_output ^ input->left_message;
	return (table_output);
}

unsigned long		ft_des_sboxes(unsigned long afterxor)
{
	unsigned int	bit6;
	int				counter;
	unsigned long	result;

	counter = 0;
	result = 0;
	while (counter < 8)
	{
		bit6 = ft_des_get_sbit6(afterxor);
		result = (result << 4) | \
			(g_sboxes[counter++][S_ROW(bit6)][S_COL(bit6)]);
	}
	return (result);
}
