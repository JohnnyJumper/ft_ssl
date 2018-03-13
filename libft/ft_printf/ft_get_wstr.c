/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:27:57 by jtahirov          #+#    #+#             */
/*   Updated: 2017/11/24 21:52:05 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		double_b(wchar_t str, char **res)
{
	**res = 0xC0 | (str >> 6);
	(*res)++;
	**res = 0x80 | (str & 0x3F);
	(*res)++;
}

static void		triple_b(wchar_t str, char **res)
{
	**res = 0xE0 | (str >> 12);
	(*res)++;
	**res = 0x80 | ((str >> 6) & 0x3F);
	(*res)++;
	**res = 0x80 | (str & 0x3F);
	(*res)++;
}

static void		quadruple_b(wchar_t str, char **res)
{
	**res = 0xF0 | (str >> 18);
	(*res)++;
	**res = 0x80 | ((str >> 12) & 0x3F);
	(*res)++;
	**res = 0x80 | ((str >> 6) & 0x3F);
	(*res)++;
	**res = 0x80 | (str & 0x3F);
	(*res)++;
}

static int		wstrlen(wchar_t *str)
{
	int		num;

	num = 0;
	while (*str)
	{
		num += ft_wcharlen(*str);
		str++;
	}
	return (num);
}

char			*ft_get_wstr(t_arg *args, va_list *ap)
{
	wchar_t		*str;
	char		*res;

	str = va_arg(*ap, wchar_t *);
	res = NULL;
	if (!str)
		return ((args->l += 6) ? ft_strdup("(null)") : ft_strdup("(null)"));
	args->l = wstrlen(str);
	res = ft_strnew(args->l);
	while (*str)
	{
		if (*str < 0x80)
			*res++ = *str;
		else if (*str < 0x800)
			double_b(*str, &res);
		else if (*str < 0x10000)
			triple_b(*str, &res);
		else if (*str < 0x200000)
			quadruple_b(*str, &res);
		str++;
	}
	res = ft_wstr_helper(res - (args->l), args);
	return (res);
}
