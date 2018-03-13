/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:47:04 by jtahirov          #+#    #+#             */
/*   Updated: 2017/11/05 14:53:16 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupper(char *str)
{
	char *ptr;

	ptr = str;
	while (*ptr)
	{
		if (ft_isletter(*ptr) && !(ft_iscapital(*ptr)))
			*ptr -= 32;
		ptr++;
	}
	return (str);
}
