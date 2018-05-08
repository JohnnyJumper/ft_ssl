/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 21:22:26 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/07 20:24:53 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_rsa.h"

static char 	*ft_decrypto_to_base64(unsigned char *bitString)
{
	char 		*encoded;
	t_binput 	base64;

	ft_bzero(&base64, sizeof(t_binput));
	base64.len = sizeof(t_dercrypto);
	base64.flag.encode = true;
	encoded = ft_base64_encode((char *)bitString, &base64);
	return (encoded);
}

int main()
{
	t_dercrypto 	main;
	unsigned long 	totient;
	unsigned char 	*bit_string;
	t_itercrypto 	iter;
	int 			total_size = 4;
	
	while (true)
	{
		ft_bzero(&main, sizeof(t_dercrypto));
		main.public_exponent = 65537;
		ft_get_primes(&main);
		main.modulus = (unsigned int)main.prime1 * (unsigned int)main.prime2;
		totient = ((unsigned int)main.prime1 - 1) * ((unsigned int)main.prime2 - 1);
		main.private_exponent = ft_get_modulo(main.public_exponent, totient);
		main.exponent1 = main.private_exponent % ((unsigned int)main.prime1 - 1);
		main.exponent2 = main.private_exponent % ((unsigned int)main.prime2 - 1);
		if ((main.public_exponent * main.private_exponent) % totient == 1)
			break ;
	};
	ft_printf("public key\n n = %lu, e = %lu\n", main.modulus, main.public_exponent);
	ft_printf("private key\n n = %lu, d = %lu\n", main.modulus, main.private_exponent);
	ft_printf("primes\n p = %lu, q = %lu\n", main.prime1, main.prime2);
	ft_printf("e is %d (%#x)\n", main.public_exponent, main.public_exponent);
	
	iter.dercrypto = main;
	for (int i=0; i < 8; i++)
		ft_printf("#%d -> %lu\n", i, iter.itercrypto[i]);
	bit_string = ft_get_asn1(&main, &total_size);
	ft_printf("-----BEGIN RSA PRIVATE KEY-----\n");
	ft_printf("%s", ft_decrypto_to_base64(bit_string));	
	ft_printf("-----END RSA PRIVATE KEY-----\n");
return (0);
}
