/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:26:39 by jtahirov          #+#    #+#             */
/*   Updated: 2017/12/06 18:12:47 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int	sign;
	int	result;

	result = 0;
	while (ATOI_CONDITION)
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -1 : sign;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
