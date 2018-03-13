/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 12:59:39 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/25 18:31:22 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char	m[13];
	int		counter;

	if (nb < 0)
		ft_putchar_fd('-', fd);
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	counter = 0;
	while (nb != 0)
	{
		m[counter] = nb % 10;
		if (m[counter] < 0)
			m[counter] = -m[counter];
		nb /= 10;
		counter++;
	}
	while (counter > 0)
	{
		ft_putchar_fd(m[counter - 1] + '0', fd);
		counter--;
	}
}
