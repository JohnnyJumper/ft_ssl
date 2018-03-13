/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:03:31 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/25 18:34:41 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *new;

	if (size <= 0)
		return (NULL);
	new = malloc(size);
	if (!new)
		return (NULL);
	ft_bzero(new, size);
	return (new);
}
