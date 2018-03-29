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

static char 	*ft_decrypto_to_base64(t_dercrypto *main)
{
	char 		*encoded;
	t_binput 	base64;

	ft_bzero(&base64, sizeof(t_binput));
	base64.len = sizeof(t_dercrypto);
	base64.flag.encode = true;
	encoded = ft_base64_encode((void *)main, &base64);
	return (encoded);
}

int main()
{
	t_dercrypto main;
	unsigned long totient;

	while (true)
	{
		ft_bzero(&main, sizeof(t_dercrypto));
		main.public_exponent = 65537;
		ft_get_primes(&main);
		main.modulus = main.prime1 * main.prime2;
		totient = (main.prime1 - 1) * (main.prime2 - 1);
		main.private_exponent = ft_get_modulo(main.public_exponent, totient);
		main.exponent1 = main.private_exponent % (main.prime1 - 1);
		main.exponent2 = main.private_exponent % (main.prime2 - 1);
		if ((main.public_exponent * main.private_exponent) % totient == 1)
			break ;
	};
	ft_printf("e is %d (%#x)\n", main.public_exponent, main.public_exponent);
	ft_printf("-----BEGIN RSA PRIVATE KEY-----\n");
	ft_printf("%s", ft_decrypto_to_base64(&main));	
	ft_printf("-----END RSA PRIVATE KEY-----\n");
return (0);
}
