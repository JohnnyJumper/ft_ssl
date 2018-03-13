/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:12:24 by jtahirov          #+#    #+#             */
/*   Updated: 2017/11/21 20:18:46 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*single_b(wint_t wide_char, t_arg *args)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = wide_char;
	args->l += 1;
	return (str);
}

static char		*double_b(wint_t wide_char, t_arg *args)
{
	char	*str;

	str = ft_strnew(2);
	str[0] = 0xC0 | (wide_char >> 6);
	str[1] = 0x80 | (wide_char & 0x3F);
	args->l += 2;
	return (str);
}

static char		*triple_b(wint_t wide_char, t_arg *args)
{
	char	*str;

	str = ft_strnew(3);
	str[0] = 0xE0 | (wide_char >> 12);
	str[1] = 0x80 | ((wide_char >> 6) & 0x3F);
	str[2] = 0x80 | (wide_char & 0x3F);
	args->l += 3;
	return (str);
}

static char		*quadruple_b(wint_t wide_char, t_arg *args)
{
	char	*str;

	str = ft_strnew(4);
	str[0] = 0xF0 | (wide_char >> 18);
	str[1] = 0x80 | ((wide_char >> 12) & 0x3F);
	str[2] = 0x80 | ((wide_char >> 6) & 0x3F);
	str[3] = 0x80 | (wide_char & 0x3F);
	args->l += 4;
	return (str);
}

char			*ft_get_wchar(t_arg *args, va_list *ap)
{
	wint_t		wide_char;
	char		*str;

	wide_char = va_arg(*ap, wint_t);
	str = NULL;
	if (wide_char < 0x80)
		str = single_b(wide_char, args);
	else if (wide_char < 0x800)
		str = double_b(wide_char, args);
	else if (wide_char < 0x10000)
		str = triple_b(wide_char, args);
	else if (wide_char < 0x200000)
		str = quadruple_b(wide_char, args);
	return (str);
}
