/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 19:43:26 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/02 19:55:21 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(void *dst, size_t size, void *src, size_t n)
{
	void	*result;

	result = (!size) ? ft_memalloc(1) : ft_memalloc(size);
	result = ft_memcpy(result, dst, size);
	ft_memcpy(result + size, src, n);
	return (result);
}
