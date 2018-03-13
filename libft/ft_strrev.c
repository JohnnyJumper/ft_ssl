/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:08:01 by jtahirov          #+#    #+#             */
/*   Updated: 2017/11/01 18:19:02 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *str)
{
	char	*start;
	char	*end;
	char	temp;
	int		length;

	start = (char *)str;
	end = start;
	while (*(end + 1))
		end++;
	length = (end - start + 1) / 2;
	while (length--)
	{
		temp = *start;
		*start++ = *end;
		*end-- = temp;
	}
	return ((char *)str);
}
