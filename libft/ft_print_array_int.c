/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 21:14:02 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/28 21:33:39 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_array_int(int *array, size_t array_size)
{
	size_t count;

	count = 0;
	while (count < array_size)
	{
		ft_putnbr(array[count]);
		ft_putchar(' ');
		count++;
	}
}
