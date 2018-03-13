/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_number2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:36:16 by jtahirov          #+#    #+#             */
/*   Updated: 2017/11/21 20:17:16 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void		get_sign(t_arg *args)
{
	if (args->val.sint < 0)
	{
		args->sign = '-';
		args->val.sint *= -1;
	}
	else if (args->flag.force_sign)
		args->sign = '+';
	else if (args->flag.space)
		args->sign = ' ';
}

static char			*get_width(t_arg *args, int val)
{
	char	*width;

	if (args->width < val)
		width = ft_strdup("");
	else
	{
		width = ft_strnew(args->width - val);
		if ((args->flag.zero && args->precision == 0) && !args->flag.left_align)
			ft_memset(width, '0', args->width - val);
		else
			ft_memset(width, ' ', args->width - val);
	}
	return (width);
}

static char			*get_precision(t_arg *args)
{
	char	*precision;
	int		pre_cpy;

	pre_cpy = args->precision;
	if (args->precision < args->l || args->precision == 0)
		precision = ft_strdup("");
	else
	{
		pre_cpy -= args->l;
		precision = ft_strnew(pre_cpy);
		ft_memset(precision, '0', pre_cpy);
	}
	return (precision);
}

static void			ft_delextra(char **precision, char **width, char **value)
{
	ft_memdel((void **)precision);
	ft_memdel((void **)width);
	ft_memdel((void **)value);
}

char				*ft_get_number2(t_arg *args, va_list *ap)
{
	char	*precision;
	char	*width;
	char	*value;
	char	*res;

	conversion_sint(args, ap);
	get_sign(args);
	value = ft_ltoa(args->val.sint, 10);
	args->l = ft_strlen(value);
	precision = get_precision(args);
	args->l = (args->precision == -1 || args->precision == -2) ? 0 : args->l;
	width = get_width(args, ft_strlen(precision) + args->l +
			((args->sign != '\0') ? 1 : 0));
	if (args->flag.left_align)
		res = ft_strmjoin(4, &args->sign, precision, value, width);
	else if ((args->precision == -2 || args->precision == -1)
			&& args->val.sint == 0)
		res = ft_strmjoin(2, width, precision);
	else if (*width == ' ')
		res = ft_strmjoin(4, width, &args->sign, precision, value);
	else
		res = ft_strmjoin(4, &args->sign, width, precision, value);
	args->l = ft_strlen(res);
	ft_delextra(&precision, &width, &value);
	return (res);
}
