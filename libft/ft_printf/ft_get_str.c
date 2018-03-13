/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:01:18 by jtahirov          #+#    #+#             */
/*   Updated: 2017/11/24 21:49:01 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_width_str(t_arg *args)
{
	int		num;
	char	*str;

	if (args->precision > 0 && args->precision < args->l)
		num = args->width - args->precision;
	else if (args->precision == -1)
		num = args->width;
	else
		num = args->width - args->l;
	num = (num < 0) ? 0 : num;
	str = ft_strnew(num);
	ft_memset(str, ' ', num);
	return (str);
}

char		*get_precision_str(t_arg *args)
{
	char	*str;

	if (args->precision > 0 && args->precision < args->l)
		str = ft_strsub(args->val.str, 0, args->precision);
	else if (args->precision == -1)
		str = ft_strdup("");
	else
		str = ft_strsub(args->val.str, 0, args->l);
	return (str);
}

char		*ft_get_str(t_arg *args, va_list *ap)
{
	char *res;
	char *value_to_print;
	char *prefix_postfix;

	args->val.str = va_arg(*ap, char *);
	if (!(args->val.str))
		args->val.str = "(null)";
	args->l = ft_strlen(args->val.str);
	value_to_print = get_precision_str(args);
	prefix_postfix = get_width_str(args);
	if (args->flag.left_align)
		res = ft_strjoin(value_to_print, prefix_postfix);
	else
		res = ft_strjoin(prefix_postfix, value_to_print);
	ft_memdel((void **)&value_to_print);
	ft_memdel((void **)&prefix_postfix);
	args->l = ft_strlen(res);
	return (res);
}
