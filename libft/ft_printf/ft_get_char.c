/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:23:00 by jtahirov          #+#    #+#             */
/*   Updated: 2017/11/21 19:56:34 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_width(t_arg *args)
{
	int		num;
	char	*width;

	num = args->width - args->l;
	num = (num < 0) ? 0 : num;
	width = ft_strnew(num);
	ft_memset(width, ' ', num);
	return (width);
}

char			*ft_get_char(t_arg *args, va_list *ap)
{
	char *res;
	char *width;

	if (args->sp == '%')
		args->val.c = '%';
	else
		args->val.c = (unsigned char)va_arg(*ap, int);
	args->l = 1;
	width = get_width(args);
	if (args->flag.left_align)
		res = ft_strmjoin(2, &args->val.c, width);
	else
		res = ft_strmjoin(2, width, &args->val.c);
	ft_memdel((void **)&width);
	args->l = (!args->val.c) ? ft_strlen(res) + 1 : ft_strlen(res);
	return (res);
}
