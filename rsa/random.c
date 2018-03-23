/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 20:52:26 by jtahirov          #+#    #+#             */
/*   Updated: 2018/03/22 22:28:50 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_rsa.h"

#ifndef WHICH_RANDOM
# define WHICH_RANDOM(x) (x == 'u' ? "/dev/urandom" : "/dev/random")
#endif

unsigned int		ft_random(int option)
{
	int				random;
	unsigned int	answer;
	int				ret;

	answer = 0;
	random = open(WHICH_RANDOM(option), O_RDONLY);
	ret = read(random, &answer, sizeof(answer));
	if (ret == -1)
	{
		ft_printf("%r Problem reading from /dev/[u]random\n", 2);
		exit(25);
	}
	close(random);
	return (answer);
}

unsigned int		ft_random_between(unsigned int a, unsigned int b, int option)
{
	return (ft_random(option) % (b + 1 - a) + a);
}
