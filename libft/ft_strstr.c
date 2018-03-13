/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:04:17 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/25 18:27:44 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char	*begin;
	const char	*pattern;

	if (*big == *little && *big == '\0')
		return ((char *)big);
	while (*big)
	{
		begin = big;
		pattern = little;
		while (*pattern && *big && *pattern == *big)
		{
			pattern++;
			big++;
		}
		if (!*pattern)
			return ((char *)begin);
		big = begin + 1;
	}
	return (NULL);
}
