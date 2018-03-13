/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectooctal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:24:26 by jtahirov          #+#    #+#             */
/*   Updated: 2017/11/24 20:59:06 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dectooctal(unsigned long long int num)
{
	char	arr[32];
	char	*asw;
	int		counter;

	ft_bzero(arr, 32);
	asw = ft_strnew(32);
	counter = 0;
	if (num == 0)
		arr[counter++] = '0';
	while (num)
	{
		arr[counter++] = num % 8 + 48;
		num /= 8;
	}
	asw = ft_strcpy(asw, ft_strrev(arr));
	return (asw);
}
