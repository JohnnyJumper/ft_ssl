/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 21:22:26 by jtahirov          #+#    #+#             */
/*   Updated: 2018/03/23 19:02:24 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_rsa.h"

static t_binput	*create_bstruct_rsa()
{
	t_binput	*new;

	new = (t_binput *)ft_memalloc(sizeof(t_binput));
	new->len = sizeof(t_ulong);
	return (new);
}

static char		*ft_rsa_to_base64(unsigned long *res)
{
	t_binput	*input_base;
	char		*answer;
	
	input_base = create_bstruct_rsa();
	answer = ft_base64_encode((char *)&res, input_base);
	return (answer);
}

int				main()
{
	unsigned int			*primes;
	unsigned long long		rsa_modulus;
	unsigned long			totient;
	unsigned int			public_constant;
	unsigned long			inverse_modulo;
	unsigned long 			temp;


	temp = 0 - 1;
	while(1)
	{
		primes = ft_get_primes();
		rsa_modulus = (t_ulong)primes[0] * (t_ulong)primes[1];
		totient = (primes[0] - 1) * (primes[1] - 1);
		public_constant = 65537;
		inverse_modulo = ft_get_modulo(public_constant, totient);
		if ((public_constant * inverse_modulo) % totient == 1)
			break ;
	}
	ft_printf("prime1 = %lu     prime2 = %lu\n", primes[0], primes[1]);
	ft_printf("n = %llu, phi = %llu, d = %llu\n", rsa_modulus, totient, inverse_modulo);
	ft_printf("e * d mod phi = %lu\n", (public_constant * inverse_modulo) % totient);
	ft_printf("%s",ft_rsa_to_base64(&inverse_modulo));
	return (0);
}
