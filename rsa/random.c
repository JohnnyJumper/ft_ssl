/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 20:52:26 by jtahirov          #+#    #+#             */
/*   Updated: 2018/03/22 21:13:33 by jtahirov         ###   ########.fr       */
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


static bool			ft_initial_sieve_test(unsigned int number)
{
	static int		primes[53] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
				43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107,
				109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179,
				181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 251};
	int				counter;

	counter = 0;
	while (counter < 53)
		if (number % primes[counter++] == 0)
			return  (false);
	return (true);
}



int					*simpleSieve(int limit, int *size)
{
	bool	*mark;
	int		prime;
	int		temp;

	mark = ft_memalloc(sizeof(*mark) * (limit + 1));
	ft_memset(mark, true, sizeof(*mark) * (limit + 1));
	prime = 2;
	temp = 0;
	*size = 0;
	while(prime * prime < limit)
	{
		if (mark[prime] == true) {
			temp = prime * 2;
			while (temp < limit)
			{
				mark[temp] = false;	
				temp += prime;
			}
		}
		prime++;
	}
	prime = 2;
	while (prime < limit)
	{
		if (mark[prime])
			*size += 1;
		prime++;
	}
	// creation of an array
	int		*result;
	
	result = ft_memalloc(sizeof(result) * (*size + 1));
	prime = 2;
	while (prime < limit)
	{
		if (mark[prime] == true)
			*result++ = prime;
		prime++;
	}
	ft_memdel((void **)&mark);
	return (result - *size);
}

static unsigned int		ft_prime_tests()
{
	unsigned int counter;
	unsigned int number;

	while (true)
	{
		counter = 0;
		number = ft_random('r');
		if (ft_initial_sieve_test(number))
			ft_printf("%r .", 2);
		else
			continue ;
		while (counter++ < 27)
		{
			if (ft_primeq(number, 64))
				ft_printf("%r +", 2);
			else
				break;
		}
		if (counter != 28)
			continue;
		else
			break;
	}
	ft_printf("%r \n", 2);
	return (number);
}

unsigned int		*ft_get_primes()
{
	unsigned int	*primes;

	primes = ft_memalloc((sizeof(*primes) * 2));
	primes[0] = ft_prime_tests();
	primes[1] = ft_prime_tests();
	return (primes);
}
