/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:27:21 by jtahirov          #+#    #+#             */
/*   Updated: 2017/11/20 16:30:35 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wcharlen(wchar_t wc)
{
	int size;

	size = 0;
	if (wc <= 127)
		size = 1;
	else if (wc <= 2047)
		size = 2;
	else if (wc <= 65535)
		size = 3;
	else if (wc <= 1114111)
		size = 4;
	return (size);
}
