/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:56:07 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/24 18:31:18 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(const char *str, int fd)
{
	if (str)
	{
		while (*str)
		{
			ft_putchar_fd(*str, fd);
			str++;
		}
	}
	ft_putchar_fd('\n', fd);
}
