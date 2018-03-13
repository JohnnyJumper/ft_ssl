/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:12:56 by jtahirov          #+#    #+#             */
/*   Updated: 2017/12/01 19:08:40 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_prefix_posfix(t_arg *args)
{
	char	*res;
	int		num;

	num = args->width - args->l;
	num = (num < 0) ? 0 : num;
	res = ft_strnew(num);
	if (args->flag.zero)
		ft_memset(res, '0', num);
	else
		ft_memset(res, ' ', num);
	return (res);
}

char			*ft_get_addr(t_arg *args, va_list *ap)
{
	char	*value;
	char	*prefix_postfix;
	char	*res;

	args->val.uint = va_arg(*ap, unsigned long int);
	value = ft_dectohex(args->val.uint);
	args->l = ft_strlen(value) + 2;
	prefix_postfix = get_prefix_posfix(args);
	if (args->flag.left_align)
		res = ft_strmjoin(3, "0x", value, prefix_postfix);
	else if (*prefix_postfix == '0')
		res = ft_strmjoin(3, "0x", prefix_postfix, value);
	else
		res = ft_strmjoin(3, prefix_postfix, "0x", value);
	args->l = ft_strlen(res);
	ft_memdel((void **)&value);
	ft_memdel((void **)&prefix_postfix);
	return (res);
}
