/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5algofunc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:43:11 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/24 00:52:06 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_md5.h"

uint32_t	ft_md5f_function(t_md5 *main, uint32_t *g, uint32_t i)
{
	*g = i;
	return ((main->part.b & main->part.c) | ((~main->part.b) & main->part.d));
}

uint32_t	ft_md5g_function(t_md5 *main, uint32_t *g, uint32_t i)
{
	*g = (5 * i + 1) % 16;
	return ((main->part.d & main->part.b) | ((~main->part.d) & main->part.c));
}

uint32_t	ft_md5h_function(t_md5 *main, uint32_t *g, uint32_t i)
{
	*g = (3 * i + 5) % 16;
	return ((main->part.b ^ main->part.c ^ main->part.d));
}

uint32_t	ft_md5i_function(t_md5 *main, uint32_t *g, uint32_t i)
{
	*g = (7 * i) % 16;
	return (main->part.c ^ (main->part.b | (~main->part.d)));
}
