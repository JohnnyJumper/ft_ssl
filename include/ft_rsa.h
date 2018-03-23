/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rsa.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 01:45:37 by jtahirov          #+#    #+#             */
/*   Updated: 2018/03/22 20:37:41 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RSA_H
# define FT_RSA_H

# include "../libft/libft.h"
# include <stdbool.h>


typedef unsigned int t_uint;

int			ft_primeq(uint64_t prime, int probability);
t_uint		ft_random(int option);
t_uint		ft_random_between(t_uint a, t_uint b, int option);
int			*simpleSieve(int limit, int *size);
t_uint		*ft_get_primes();

#endif
