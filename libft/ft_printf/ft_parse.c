/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:03:42 by jtahirov          #+#    #+#             */
/*   Updated: 2017/12/01 21:41:02 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_specifier(char **format, t_arg *args)
{
	char	*tmp;

	args->sp = **format;
	tmp = NULL;
	if (args->sp == 'p')
		args->flag.alt_mode = true;
	if ((args->sp == 'U' || args->sp == 'O' ||
			args->sp == 'D') && !(ft_strchr(args->length, 'l')))
		add_length_l(args);
	(*format)++;
}

void	parse_flags(char **format, t_arg *args)
{
	char	*last_flag;

	last_flag = *format;
	while (FORMAT_FLAGS)
		last_flag++;
	if (ft_memchr(*format, '#', last_flag - *format))
		args->flag.alt_mode = true;
	if (ft_memchr(*format, '-', last_flag - *format))
		args->flag.left_align = true;
	if (ft_memchr(*format, '+', last_flag - *format))
		args->flag.force_sign = true;
	if (ft_memchr(*format, '0', last_flag - *format))
		args->flag.zero = true;
	if (ft_memchr(*format, ' ', last_flag - *format))
		args->flag.space = true;
	(*format) = (last_flag == *format) ? *format : last_flag;
}

void	parse_width(char **format, t_arg *args, va_list *ap)
{
	char	*last_width;

	last_width = *format;
	while (WIDTH_FLAGS)
		last_width++;
	if (**format == '*')
		args->width = va_arg(*ap, int);
	else
		args->width = ft_atoi(*format);
	(*format) = (last_width == *format) ? *format : last_width;
	if (**format == '*')
		(*format)++;
}

void	parse_precision(char **format, t_arg *args, va_list *ap)
{
	char	*last_precision;

	last_precision = *format;
	if (*last_precision != '.')
		return ;
	else
		last_precision += ((*format)++) ? 1 : 0;
	while (PRECISION_FLAGS)
		last_precision++;
	if (*last_precision == '*')
	{
		args->precision = va_arg(*ap, int);
		last_precision++;
		args->precision = (args->precision == 0) ? -2 : args->precision;
	}
	else
		args->precision = ft_atoi(*format);
	if (**format == '0')
		args->precision = -2;
	if (last_precision == *format)
		args->precision = -1;
	(*format) = (last_precision == *format) ? *format : last_precision;
}

void	parse_length(char **format, t_arg *args)
{
	char	*last_length;
	char	*tmp;

	last_length = *format;
	while (LENGTH_FLAGS)
		last_length++;
	tmp = args->length;
	args->length = ft_strsub(*format, 0, last_length - *format);
	if (tmp)
		ft_memdel((void **)&tmp);
	(*format) = (last_length == *format) ? *format : last_length;
}
