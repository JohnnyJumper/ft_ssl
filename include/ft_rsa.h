/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rsa.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 01:45:37 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/08 19:55:15 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RSA_H
# define FT_RSA_H

# include "../libft/libft.h"
# include "../include/ft_ssl.h"

# define VERSION "\0x02\0x01\0x00"
# define SEQUENCE_ASN1 0x30
# define INT_ASN1 0x02
# define CRT(x, y) ((1 / (MIN(x, y))) % (MAX(x, y)))


typedef unsigned int    t_uint;
typedef unsigned long   t_ulong;
typedef unsigned char   t_uchar;

// RSAPrivateKey ::= SEQUENCE {
//   version           Version,
//   modulus           INTEGER,  -- n
//   publicExponent    INTEGER,  -- e
//   privateExponent   INTEGER,  -- d
//   prime1            INTEGER,  -- p
//   prime2            INTEGER,  -- q
//   exponent1         INTEGER,  -- d mod (p-1)
//   exponent2         INTEGER,  -- d mod (q-1)
//   coefficient       INTEGER,  -- (inverse of q) mod p
//   otherPrimeInfos   OtherPrimeInfos OPTIONAL
// }

typedef struct  s_dercrypto
{
    unsigned long     modulus;
    unsigned long     public_exponent;
    unsigned long     priv_exponent;
    unsigned long     prime1;
    unsigned long     prime2;
    unsigned long     exponent1;
    unsigned long     exponent2;
    unsigned long     coefficient;
}               t_dercrypto;

typedef union   u_itercrypto
{
    t_dercrypto     dercrypto;
    unsigned long   itercrypto[8]; 
}               t_itercrypto;


int			    ft_primeq(uint64_t prime, int probability);
t_uint  		ft_random(int option);
t_uint  		ft_random_between(t_uint a, t_uint b, int option);
void		    ft_get_primes(t_dercrypto *main);
t_ulong 		ft_get_modulo(t_uint pub, t_ulong totient);
unsigned char   *ft_get_asn1(t_dercrypto *main, int *total_size);
unsigned long   modinv(unsigned long u, unsigned long v);
void            ft_genrsa(int argc, char **argv, bool cbc_mode);


#endif
