/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:24:14 by jtahirov          #+#    #+#             */
/*   Updated: 2017/11/14 21:00:54 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dectohex(unsigned long long int num)
{
	char	arr[32];
	char	*ans;
	int		remainder;
	int		counter;

	counter = 0;
	ft_bzero(arr, 32);
	ans = ft_strnew(32);
	if (num == 0)
		arr[counter++] = '0';
	while (num)
	{
		remainder = num % 16;
		if (remainder < 10)
			arr[counter++] = remainder + 48;
		else
			arr[counter++] = remainder + 87;
		num /= 16;
	}
	ans = ft_strcpy(ans, ft_strrev(arr));
	return (ans);
}
