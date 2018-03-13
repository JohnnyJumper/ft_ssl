/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:29:49 by jtahirov          #+#    #+#             */
/*   Updated: 2017/12/01 21:18:18 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_zeros(t_arg *args)
{
	int		zeros;
	char	*z;

	zeros = 0;
	if (args->flag.alt_mode && args->val.uint != 0)
		zeros++;
	if (args->precision > args->l + zeros)
		zeros = args->precision - args->l;
	if (!args->flag.left_align && args->flag.zero)
		zeros += args->width - (zeros + args->l);
	zeros = (zeros < 0) ? 0 : zeros;
	z = ft_strnew(zeros);
	ft_memset(z, '0', zeros);
	return (z);
}

static char		*get_spaces(t_arg *args, int zeros)
{
	int		spaces;
	char	*sp;

	spaces = 0;
	if (args->flag.left_align)
		spaces = args->width - (zeros + args->l);
	else if (!args->flag.zero)
		spaces = args->width - (zeros + args->l);
	spaces = (spaces < 0) ? 0 : spaces;
	sp = ft_strnew(spaces);
	ft_memset(sp, ' ', spaces);
	return (sp);
}

char			*ft_get_octal(t_arg *args, va_list *ap)
{
	char	*value;
	char	*z;
	char	*sp;
	char	*res;

	conversion_uint(args, ap);
	value = ft_dectooctal(args->val.uint);
	args->l = (args->precision == -1 || args->precision == -2)
		? 0 : ft_strlen(value);
	z = get_zeros(args);
	sp = get_spaces(args, ft_strlen(z));
	if (args->flag.left_align)
		res = ft_strmjoin(3, z, value, sp);
	else if ((args->precision == -1 || args->precision == -2)
			&& args->val.uint == 0 && !args->flag.alt_mode)
		res = ft_strmjoin(2, sp, z);
	else
		res = ft_strmjoin(3, sp, z, value);
	ft_memdel((void **)&z);
	ft_memdel((void **)&sp);
	ft_memdel((void **)&value);
	args->l = ft_strlen(res);
	return (res);
}
