/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 21:22:26 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/08 18:49:26 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_rsa.h"

void 	ft_rsa_wrap(void)
{
	t_dercrypto 	main;
	unsigned long 	totient;
	unsigned char 	*bit_string;
	t_itercrypto 	iter;
	int 			total_size = 3;
	
	while (true)
	{
		ft_bzero(&main, sizeof(t_dercrypto));
		main.public_exponent = 65537;
		ft_get_primes(&main);
		main.modulus = (t_uint)main.prime1 * (t_uint)main.prime2;
		totient = ((t_uint)main.prime1 - 1) * ((t_uint)main.prime2 - 1);
		main.priv_exponent = ft_get_modulo(main.public_exponent, totient);
		main.exponent1 = main.priv_exponent % ((t_uint)main.prime1 - 1);
		main.exponent2 = main.priv_exponent % ((t_uint)main.prime2 - 1);
		main.coefficient = ft_modinv(MIN(main.prime1, main.prime2), MAX(main.prime1, main.prime2));
		if (main.coefficient == 1)
			continue ;
		if ((main.public_exponent * main.priv_exponent) % totient == 1)
			break ;
	};
	iter.dercrypto = main;
	bit_string = ft_get_asn1(&main, &total_size);
	ft_printf("-----BEGIN RSA PRIVATE KEY-----\n");
	ft_printf("%s", base64_encodeV2(bit_string, &total_size));
	ft_printf("-----END RSA PRIVATE KEY-----\n");
}


void 	ft_rsa(int argc, char **argv, bool cbc_mode) {

}