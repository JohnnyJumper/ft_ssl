/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rsa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 21:22:26 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/08 20:04:44 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_rsa.h"

extern char 	*g_optarg;
extern int 		g_optind;

static void 	ft_genrsa_usage() {
	printf("usage: ft_ssl genrsa [i] [file] [o] [file]\n");
	exit(11);
}

unsigned char  	*ft_rsa_wrap(int 	*total_size)
{
	t_dercrypto 	main;
	unsigned long 	totient;
	unsigned char 	*bit_string;
	t_itercrypto 	iter;
	
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
	bit_string = ft_get_asn1(&main, total_size);
	return (base64_encodeV2(bit_string, total_size));
}

static void 	ft_print_private(unsigned char *answer, int fd_output)
{
	unsigned char *tmp;

	tmp = answer;
	answer = (t_uchar *)ft_strjoin("-----BEGIN RSA PRIVATE KEY-----\n", (char *)
																	answer);
	ft_strdel((char **)&tmp);
	tmp = answer;
	answer = (t_uchar *)ft_strjoin((char *)answer,
				"-----END RSA PRIVATE KEY-----\n");
	ft_strdel((char **)&tmp);
	write(fd_output, answer, ft_strlen((char *)answer));

}

void 	ft_genrsa(int argc, char **argv, bool cbc_mode)
{
	int 			fd_input;
	int 			fd_output;
	char			ch;
	unsigned char 	*answer;
	int 			total_size;

	cbc_mode = false;
	fd_output = 1;
	fd_input = 0;
	total_size = 3;
	argv--;
	while((ch = ft_getopt(argc, argv, "i:o:")) != -1)
	{
		if (ch == 'i')
			fd_input = ft_openfile(g_optarg, true);
		else if (ch == 'o')
			fd_output = ft_openfile(g_optarg, false);
		else 
			ft_genrsa_usage();
	}
	answer = ft_rsa_wrap(&total_size);
	ft_print_private(answer, fd_output);
}