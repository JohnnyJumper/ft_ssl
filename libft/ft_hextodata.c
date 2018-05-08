/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextodata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:03:15 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/07 20:15:20 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char *ft_hextodata(char* hex_string)
{
    size_t          slength;
    unsigned char   *data;
    size_t          index;
    char            c;
    int             value;

    if(hex_string == NULL) 
       return (NULL);
    slength = strlen(hex_string);
    if((slength % 2) != 0) {
       return (NULL);
    }
    data = ft_memalloc(slength / 2);
    index = -1;
    while (++index < slength) {
        c = ft_tolower(hex_string[index]);
        value = 0;
        if(c >= '0' && c <= '9')
            value = (c - '0');
        else if (c >= 'a' && c <= 'f')
             value = (10 + (c - 'a'));
        else
            return (NULL);
        data[(index/2)] += value << (((index + 1) % 2) * 4);
    }
    return data;
}