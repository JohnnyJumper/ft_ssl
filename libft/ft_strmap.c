/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:54:50 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/25 18:31:55 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*temp;

	if (!s)
		return (NULL);
	new = ft_strnew(ft_strlen(s));
	if (!new)
		return (NULL);
	temp = new;
	while (*s)
		*temp++ = f(*s++);
	return (new);
}
