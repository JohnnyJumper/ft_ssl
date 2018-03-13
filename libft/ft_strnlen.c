/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 19:10:33 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/26 06:51:05 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *str, size_t n)
{
	size_t counter;

	counter = 0;
	while (*(str + (int)counter) && n > 0)
	{
		counter++;
		n--;
	}
	return (counter);
}
