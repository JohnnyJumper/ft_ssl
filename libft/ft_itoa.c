/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 03:04:24 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/25 18:37:31 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_dignum(int n, int *negative)
{
	int count;

	count = 1;
	*negative = (n >= 0) ? 0 : 1;
	if (*negative)
	{
		n = ABS(n);
		count++;
	}
	while (n)
		count += (((n /= 10) > 0) ? 1 : 0);
	return (count);
}

static	int		ft_checkover(int n)
{
	if (n == MIN_INT)
		return (1);
	return (0);
}

char			*ft_itoa(int n)
{
	char	*new;
	int		negative;
	int		str_len;

	str_len = ft_dignum(n, &negative);
	new = ft_strnew(str_len);
	if (ft_checkover(n))
		return (new = ft_strdup("-2147483648"));
	if (!new)
		return (NULL);
	if (!n)
	{
		*new = (!n) ? '0' : *new;
		return (new);
	}
	*new = (negative) ? '-' : *new;
	new = new + str_len - 1;
	n = (negative) ? ABS(n) : n;
	while (n)
	{
		*new-- = (n % 10) + '0';
		n /= 10;
		new = (!n) ? new += 1 : new;
	}
	return ((negative) ? new -= 1 : new);
}
