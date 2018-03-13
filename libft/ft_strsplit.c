/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 04:25:42 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/04 23:53:54 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_words(char const *str, int c)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str != c && (!*(str + 1) || *(str + 1) == c))
			count++;
		str++;
	}
	return (count);
}

static	char	*ft_assign_and_check(char const **s, char **str, char *str_cpy)
{
	if (!*s)
		return (NULL);
	*str = ft_strdup(*s);
	if (!*str)
		return (NULL);
	str_cpy = *str;
	return (str_cpy);
}

static	char	**ft_duplicate_strings(char **new, int length)
{
	new -= length;
	while (*new)
	{
		*new = ft_strdup(*new);
		if (!*new)
			return (NULL);
		new++;
	}
	return (new);
}

char			**ft_strsplit(char const *s, int c)
{
	char	**new;
	int		length;
	char	*str;
	char	*str_cpy;
	char	*sep;

	str_cpy = NULL;
	if (!(str_cpy = ft_assign_and_check(&s, &str, str_cpy)))
		return (NULL);
	length = ft_words(str, c);
	if (!(new = (char **)ft_memalloc((length + 1) * sizeof(new))))
		return (NULL);
	while (TRUE)
	{
		if (*str != c && *str)
			*new++ = str;
		sep = ft_strchr(str, c);
		if (!sep)
			break ;
		*sep = '\0';
		str = sep + 1;
	}
	new = ft_duplicate_strings(new, length);
	ft_strdel((void *)&str_cpy);
	return (new - length);
}
