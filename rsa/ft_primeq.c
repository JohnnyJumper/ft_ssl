/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_primeq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 01:44:17 by jtahirov          #+#    #+#             */
/*   Updated: 2018/03/22 21:07:06 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_rsa.h"

static unsigned int	ft_urandom()
{
	int				random;
	unsigned long	answer;
	int				ret;

	answer = 0;
	random = open("/dev/urandom", O_RDONLY);
	ret = read(random, &answer, sizeof(answer));
	close(random);
	return (answer);
}

/* static int	ft_equation(int phi, int *power) */
/* { */
/* 	*power = 0; */
/* 	while (phi % 2 == 0) */
/* 	{ */
/* 		phi /= 2; */
/* 		*power += 1; */
/* 	} */
/* 	return (phi); */
/* } */


static int	ft_miller_test(int phi, int prime)
{
	int ran;
	int exp;


	ran = (2 + ft_urandom()) % (prime - 4);
	exp = ft_power(ran, phi, prime);
	if (exp == 1 || exp == prime - 1)
		return (true);
	while (phi != prime - 1)
	{
		exp = ft_power(exp, 2, prime);
		phi *= 2;
		if (exp == 1)
			return (false);
		if (exp == prime - 1)
			return (true);
	}
	return (false);
}

int			ft_primeq(uint64_t prime, int probability)
{
	int		phi;
	int		counter;

	if (prime <= 1 || prime == 4)
		return (0);
	if (prime <= 3)
		return (1);

	phi = prime - 1;
	while (phi % 2 == 0)
		phi /= 2;
	counter = 0;
	while (counter++ < probability)
	{
		if (!ft_miller_test(phi, prime))
			return(0);
	}
	return (1);
}
