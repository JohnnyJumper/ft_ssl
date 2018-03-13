/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:56:07 by jtahirov          #+#    #+#             */
/*   Updated: 2017/11/24 19:04:13 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

void	ft_putstr(const char *str)
{
	int x;

	x = 0;
	if (!str)
		return ;
	while (str[x++])
		;
	write(1, str, x);
}
