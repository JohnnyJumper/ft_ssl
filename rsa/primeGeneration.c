/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primeGeneration.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 22:27:30 by jtahirov          #+#    #+#             */
/*   Updated: 2018/03/23 02:45:05 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_rsa.h"

#ifndef UINT_MAX
# define UINT_MAX 2147483648
#endif

#ifndef SAFE_MIN 
# define SAFE_MIN 3037000499
#endif

static bool			ft_initial_sieve_test(unsigned int number)
{
	int				counter;
	static int		primes[53] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
				43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107,
				109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179,
				181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 251};

	counter = 0;
	while (counter < 53)
		if (number % primes[counter++] == 0)
			return  (false);
	return (true);
}

static unsigned int		ft_prime_tests(bool flag)
{
	unsigned int counter;
	unsigned int number;

	while (true)
	{
		counter = 0;
		number = ft_random_between(SAFE_MIN, UINT_MAX, 'r');
		if (ft_initial_sieve_test(number))
			(flag) ? ft_printf("%r .", 2) : 0;
		else
			continue ;
		while (counter++ < 27)
		{
			if (ft_primeq(number, 64))
			(flag) ? ft_printf("%r +", 2) : 0;
			else
				break;
		}
		if (counter != 28)
			continue;
		else
			break;
	}
		(flag) ? ft_printf("%r \n", 2) : 0;
	return (number);
}

void		ft_get_primes(t_dercrypto *main)
{
	static bool		flag = true;
/* DON'T FORGET TO FREE THIS SHIT */
	(flag) ? ft_printf("Generating RSA private key, 64 bit long modulus\n") : 0;
	main->prime1 = ft_prime_tests(flag);
	main->prime2 = ft_prime_tests(flag);
	flag = false;
}
