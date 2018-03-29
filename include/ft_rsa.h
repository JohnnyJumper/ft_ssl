/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rsa.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 01:45:37 by jtahirov          #+#    #+#             */
/*   Updated: 2018/03/23 02:50:49 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RSA_H
# define FT_RSA_H

# include "../libft/libft.h"
# include "../include/ft_ssl.h"


typedef unsigned int t_uint;
typedef unsigned long t_ulong;
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
    unsigned long     private_exponent;
    unsigned int      prime1;
    unsigned int      prime2;
    unsigned long     exponent1;
    unsigned long     exponent2;
    unsigned long     coefficient;
}               t_dercrypto;


int			ft_primeq(uint64_t prime, int probability);
t_uint		ft_random(int option);
t_uint		ft_random_between(t_uint a, t_uint b, int option);
void		ft_get_primes(t_dercrypto *main);
t_ulong		ft_get_modulo(t_uint pub, t_ulong totient);

#endif
