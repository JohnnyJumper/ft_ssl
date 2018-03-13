/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 13:57:06 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/30 16:48:43 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char *ptr1;
	const unsigned char *ptr2;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	while (*ptr1 && *ptr2)
		ptr1 += (ptr2++) ? 1 : 1;
	if (*ptr1 || *ptr2)
		return (*ptr1 - *ptr2);
	return (ft_memcmp((void *)s1, (void *)s2,
				(size_t)(ptr1 - (const unsigned char *)s1)));
	return (0);
}
