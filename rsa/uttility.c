/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uttility.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 23:04:36 by jtahirov          #+#    #+#             */
/*   Updated: 2018/03/23 01:48:55 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_rsa.h"

enum			e_modulo_worker{s, s_new, t, t_new, temp_s, temp_t, all};


static void		ft_init_workers(long int worker[],t_uint pub, t_ulong totient)
{
	ft_bzero(worker, all * sizeof(t_ulong));
	worker[s] = totient;
	worker[s_new] = pub;
	worker[t] = totient;
	worker[t_new] = 1;
}


t_ulong	ft_get_modulo(t_uint pub, t_ulong totient)
{
	long int	worker[all];
	t_ulong		temp;
	// t_ulong		answer;

	ft_init_workers(worker, pub, totient);
	while(1)
	{
		temp = worker[s] / worker[s_new];
		worker[temp_s] = (worker[s] - (temp * worker[s_new]));
		worker[temp_s] = (worker[temp_s] < 0) ? worker[temp_s] + totient : worker[temp_s];
		worker[temp_t] = (worker[t] - (temp * worker[t_new]));
		worker[temp_t] = (worker[temp_t] < 0) ? worker[temp_t] + totient : worker[temp_t];
		worker[s] = worker[s_new];
		worker[s_new] = worker[temp_s];
		worker[t] = worker[t_new];
		worker[t_new] = worker[temp_t];
		if (worker[s_new] == 1 || worker[t_new] == 1)
			break ;
	}
	// answer = (worker[s_new] == 1) ? worker[t_new] : worker[s_new];
	return(worker[t_new]);
}
