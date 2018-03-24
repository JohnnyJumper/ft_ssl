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

int			ft_primeq(uint64_t prime, int probability);
t_uint		ft_random(int option);
t_uint		ft_random_between(t_uint a, t_uint b, int option);
t_uint		*ft_get_primes();
t_ulong		ft_get_modulo(t_uint pub, t_ulong totient);

#endif
