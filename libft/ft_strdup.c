/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 19:44:09 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/24 01:46:32 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		length;
	char	*new;

	length = ft_strlen(src);
	new = (char *)malloc(sizeof(char) * (length + 1));
	if (!new)
		return (NULL);
	while (*src != '\0')
	{
		*new = *src;
		src++;
		new++;
	}
	*new = '\0';
	return (new - length);
}
