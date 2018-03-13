/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_unumber2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:36:16 by jtahirov          #+#    #+#             */
/*   Updated: 2017/11/21 20:20:23 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_width(t_arg *args, int val)
{
	char	*width;

	if (args->width < val)
		width = ft_strdup("");
	else
	{
		width = ft_strnew(args->width - val);
		if (args->flag.zero && args->precision == 0 && !args->flag.left_align)
			ft_memset(width, '0', args->width - val);
		else
			ft_memset(width, ' ', args->width - val);
	}
	return (width);
}

static char		*get_precision(t_arg *args)
{
	char	*precision;

	if (args->precision < args->l || args->precision == 0)
		precision = ft_strdup("");
	else
	{
		args->precision -= args->l;
		precision = ft_strnew(args->precision);
		ft_memset(precision, '0', args->precision);
	}
	return (precision);
}

char			*ft_get_unumber2(t_arg *args, va_list *ap)
{
	char	*precision;
	char	*width;
	char	*value;
	char	*res;

	conversion_uint(args, ap);
	value = ft_ltoa(args->val.uint, 10);
	args->l = ft_strlen(value);
	precision = get_precision(args);
	args->l = (args->precision == -1 || args->precision == -2) ? 0 : args->l;
	width = get_width(args, ft_strlen(precision) + args->l +
			((args->sign != '\0') ? 1 : 0));
	if (args->flag.left_align)
		res = ft_strmjoin(3, precision, value, width);
	else if ((args->precision == -2 || args->precision == -1)
			&& args->val.uint == 0)
		res = ft_strmjoin(2, width, precision);
	else
		res = ft_strmjoin(3, width, precision, value);
	args->l = ft_strlen(res);
	ft_memdel((void **)&precision);
	ft_memdel((void **)&width);
	ft_memdel((void **)&value);
	return (res);
}
