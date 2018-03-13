/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 14:22:55 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/25 18:24:25 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *des, const char *src, size_t n)
{
	char	*temp;
	size_t	counter;

	temp = des;
	counter = 0;
	while (*(src + counter) && (counter < n))
	{
		*(temp + counter) = *(src + counter);
		counter++;
	}
	while (counter < n)
	{
		*(temp + counter) = '\0';
		counter++;
	}
	return (des);
}
