/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:20:09 by jtahirov          #+#    #+#             */
/*   Updated: 2017/11/24 21:52:44 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_wstr_helper(char *res, t_arg *args)
{
	char	*value_to_print;
	char	*prefix_postfix;
	char	*tmp;

	args->val.str = res;
	value_to_print = get_precision_str(args);
	prefix_postfix = get_width_str(args);
	tmp = res;
	if (args->flag.left_align)
		res = ft_strjoin(value_to_print, prefix_postfix);
	else
		res = ft_strjoin(prefix_postfix, value_to_print);
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&value_to_print);
	ft_memdel((void **)&prefix_postfix);
	args->l = ft_strlen(res);
	return (res);
}
