/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 03:17:11 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/25 18:25:29 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print2d(char **array)
{
	if (!array)
		return ;
	while (*array)
	{
		ft_putstr(*array);
		if (*(array + 1))
			ft_putchar('\n');
		else
			ft_putstr("\nNULL\n");
		array++;
	}
}
