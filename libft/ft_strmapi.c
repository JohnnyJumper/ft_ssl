/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:54:50 by jtahirov          #+#    #+#             */
/*   Updated: 2017/09/25 19:09:59 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		count;

	if (!s)
		return (NULL);
	new = ft_strnew(ft_strlen(s));
	if (!new)
		return (NULL);
	count = 0;
	while (s[count])
	{
		new[count] = f(count, s[count]);
		count++;
	}
	return (new);
}
