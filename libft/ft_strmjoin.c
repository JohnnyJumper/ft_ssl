/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:26:44 by jtahirov          #+#    #+#             */
/*   Updated: 2017/11/08 20:32:32 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

char	*ft_strmjoin(int num, ...)
{
	va_list ap;
	char	*res;
	char	*tmp;
	char	*arg;

	res = ft_strnew(0);
	va_start(ap, num);
	while (num--)
	{
		arg = va_arg(ap, char *);
		tmp = res;
		res = ft_strjoin(tmp, arg);
		ft_memdel((void **)&tmp);
	}
	va_end(ap);
	return (res);
}
