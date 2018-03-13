/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:03:19 by jtahirov          #+#    #+#             */
/*   Updated: 2017/11/04 20:49:59 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa(unsigned long n, int base)
{
	char			*tail;
	char			*head;
	char			*buf;
	unsigned long	rem;
	int				counter;

	if (base < 2 || base > 36)
		base = 10;
	buf = ft_strnew(LONGSIZE);
	tail = &buf[LONGSIZE - 1];
	head = buf;
	if (!n)
		*tail-- = '0';
	counter = 1;
	while (n)
	{
		rem = n % base;
		*tail-- = (char)(rem + ((9L < rem) ? ('A' - 10L) : '0'));
		n /= base;
		counter++;
	}
	ft_memcpy(head, ++tail, counter);
	head = ft_strdup(head);
	ft_memdel((void **)&buf);
	return (head);
}
