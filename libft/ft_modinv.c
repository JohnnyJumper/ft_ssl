/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modinv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:15:15 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/08 13:23:25 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

enum workers{u1, u3, v1, v3, t1, t3, q};

unsigned long ft_modinv(unsigned long u, unsigned long v){
	unsigned long 	worker[7];
	int 			iter;

	worker[u1] = 1;
	worker[u3] = u;
	worker[v1] = 0;
	worker[v3] = v;

	iter = 1;
	while (worker[v3]) {
		worker[q] = worker[u3] / worker[v3];
		worker[t3] = worker[u3] % worker[v3];
		worker[t1] = worker[v1];
		worker[v1] = worker[t1];
		worker[u3] = worker[v3];
		worker[v3] = worker[t3];
		iter = -iter;
	}
	if (worker[u3] != 1)
		return(0);
	return ((iter < 0) ? v - worker[u1] : worker[u1]);
}