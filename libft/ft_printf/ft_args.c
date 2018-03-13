/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:43:47 by jtahirov          #+#    #+#             */
/*   Updated: 2017/12/30 16:57:21 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg		*ft_argnew(int fd_output)
{
	t_arg	*new;

	new = (t_arg *)ft_memalloc(sizeof(t_arg));
	new->width = 0;
	new->precision = 0;
	new->length = ft_strnew(0);
	new->sp = '.';
	new->fd_output = fd_output;
	return (new);
}

void		ft_argdelete(t_arg *args)
{
	ft_memdel((void **)&args->length);
	ft_memdel((void **)&args);
}

void		free_num(char **n, char **z, char **s, char **w)
{
	ft_memdel((void **)n);
	ft_memdel((void **)z);
	ft_memdel((void **)s);
	ft_memdel((void **)w);
}

void		add_length_l(t_arg *args)
{
	char	*tmp;

	tmp = args->length;
	args->length = ft_strjoin(args->length, "l");
	ft_memdel((void **)&tmp);
}
