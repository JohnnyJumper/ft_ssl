/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 16:23:43 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/30 16:22:06 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *des, const char *src)
{
	unsigned int counter;

	counter = 0;
	while (*(src + counter))
	{
		*(des + counter) = *(src + counter);
		counter++;
	}
	*(des + counter) = '\0';
	return (des);
}
