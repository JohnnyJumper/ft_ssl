/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 20:52:26 by jtahirov          #+#    #+#             */
/*   Updated: 2018/03/20 00:30:25 by jtahirov         ###   ########.fr       */
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

int		*simpleSieve(int limit, int *size)
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


/* void simpleSieve(int limit, vector<int> &prime) */
/* { */
    /* for (int p=2; p*p<limit; p++) */
    /* { */
    /*     // If p is not changed, then it is a prime */
    /*     if (mark[p] == true) */
    /*     { */
    /*         // Update all multiples of p */
    /*         for (int i=p*2; i<limit; i+=p) */
    /*             mark[i] = false; */
    /*     } */
    /* } */
 
    /* // Print all prime numbers and store them in prime */
    /* for (int p=2; p<limit; p++) */
    /* { */
    /*     if (mark[p] == true) */
    /*     { */
    /*         prime.push_back(p); */
    /*         cout << p << " "; */
    /*     } */
    /* } */
