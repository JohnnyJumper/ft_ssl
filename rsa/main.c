/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 21:22:26 by jtahirov          #+#    #+#             */
/*   Updated: 2018/03/20 00:33:05 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_rsa.h"
#include <math.h>

int		main()
{
	int		*primes;
	int		*ptr;
	int		size;
	int		i;
	int		max;

	size = 20;
	ptr = &size;
	max = 100000000;
	primes = simpleSieve(max, ptr);
	printf("This is max = %d,  and this is sqrt(max) = %f\n", max, sqrt(max));

	for (i = 0; i < (*ptr - 2); i++)
		printf("%d ", primes[i]);
	printf("%d\n", primes[i + 1]);
	return (0);
}
