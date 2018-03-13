/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:41:44 by jtahirov          #+#    #+#             */
/*   Updated: 2017/12/01 22:15:44 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_spaces(t_arg *args, char *prefix)
{
	char	*s;
	int		sp;
	int		zeros;

	zeros = ft_strlen(prefix);
	sp = args->width - (args->l + zeros);
	sp = (sp < 0) ? 0 : sp;
	s = ft_strnew(sp);
	(args->flag.zero && !args->flag.left_align)
		? ft_memset(s, '0', sp) : ft_memset(s, ' ', sp);
	return (s);
}

static char		*get_prefix(t_arg *args)
{
	int		ifalt;
	int		zeros;
	char	*prefix;

	ifalt = (args->flag.alt_mode) ? 1 : 0;
	zeros = args->precision - args->l;
	zeros = (zeros < 0) ? 0 : zeros;
	prefix = (ifalt) ? ft_strnew(zeros + 2) : ft_strnew(zeros);
	if (ifalt && args->val.uint != 0)
	{
		prefix[0] = '0';
		prefix[1] = 'x';
		ft_memset(prefix + 2, '0', zeros);
	}
	else
		ft_memset(prefix, '0', zeros);
	return (prefix);
}

static void		ft_free(char **sp, char **prefix, char **value)
{
	ft_memdel((void **)sp);
	ft_memdel((void **)prefix);
	ft_memdel((void **)value);
}

char			*ft_get_hex(t_arg *args, va_list *ap)
{
	char	*myhex;
	char	*prefix;
	char	*sp;
	char	*value;

	conversion_uint(args, ap);
	value = ft_dectohex(args->val.uint);
	if (args->precision == -1 || args->precision == -2)
		args->l = 0;
	else
		args->l = ft_strlen(value);
	prefix = get_prefix(args);
	sp = get_spaces(args, prefix);
	if (args->flag.left_align)
		myhex = ft_strmjoin(3, prefix, value, sp);
	else if ((args->precision == -1 || args->precision == -2)
			&& args->val.uint == 0)
		myhex = ft_strmjoin(2, sp, prefix);
	else if (sp[0] == ' ')
		myhex = ft_strmjoin(3, sp, prefix, value);
	else
		myhex = ft_strmjoin(3, prefix, sp, value);
	ft_free(&sp, &prefix, &value);
	args->l = ft_strlen(myhex);
	return (myhex);
}

char			*ft_hex_wrapper(t_arg *args, va_list *ap)
{
	return (ft_strupper(ft_get_hex(args, ap)));
}
