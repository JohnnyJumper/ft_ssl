/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_subkey_routine.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 21:51:14 by jtahirov          #+#    #+#             */
/*   Updated: 2017/12/30 16:08:33 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/des.h"

static void		ft_lshift(t_long *l_k, t_long *r_k, int *i)
{
	int		times;

	if (*i >= 16)
	{
		*l_k = 0;
		*r_k = 0;
		*i = 0;
	}
	else
	{
		times = TIMES(*i);
		*i += 1;
		while (times--)
		{
			*l_k = (((*l_k & 0x7FFFFFF) << 1) | (*l_k >> 27));
			*r_k = (((*r_k & 0x7FFFFFF) << 1) | (*r_k >> 27));
		}
	}
}

static void		ft_create_kparts(t_long *l_k, t_long *r_k, t_dinput *input)
{
	t_long	key56;

	key56 = permutation(g_perm1, 56, &input->key, false);
	*l_k = key56 >> 28;
	*r_k = key56 & 0xFFFFFFF;
}

t_long			ft_des_subkey(t_dinput *input)
{
	static t_long		l_k;
	static t_long		r_k;
	t_long				key56;
	static int			i;
	t_long				subkey;

	if (input->init_k == 0)
		ft_create_kparts(&l_k, &r_k, input);
	ft_lshift(&l_k, &r_k, &i);
	key56 = (l_k << 28) | r_k;
	subkey = permutation(g_perm2, 48, &key56, false);
	input->init_k++;
	input->init_k = (input->init_k == 16) ? 0 : input->init_k;
	return (subkey);
}
