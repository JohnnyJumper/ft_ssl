/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:44:15 by jtahirov          #+#    #+#             */
/*   Updated: 2017/12/28 19:23:58 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_exec(char **format, va_list *ap, int fd_output)
{
	t_arg	*args;

	args = ft_argnew(fd_output);
	parse_flags(format, args);
	parse_width(format, args, ap);
	parse_precision(format, args, ap);
	parse_length(format, args);
	parse_specifier(format, args);
	return ((ft_logic(ap, args)));
}

int		ft_logic(va_list *ap, t_arg *args)
{
	char	*value;
	t_func	f;
	int		res;

	f = get_func(args->sp);
	if (f)
		value = f(args, ap);
	else if (args->width != 0)
	{
		args->l = args->width;
		value = ft_strnew(args->width);
		ft_memset(value, ' ', args->width);
		ft_memset(value + args->width - 1, args->sp, 1);
	}
	else
	{
		args->l = 1;
		value = ft_strnew(1);
		ft_memset(value, args->sp, 1);
	}
	res = write(args->fd_output, value, args->l);
	ft_memdel((void **)&value);
	ft_argdelete(args);
	return (res);
}
