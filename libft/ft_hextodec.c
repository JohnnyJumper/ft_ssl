/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rsa.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 01:45:37 by jtahirov          #+#    #+#             */
/*   Updated: 2018/03/23 02:50:49 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function to convert hexadecimal to decimal
int ft_hextodec(char hexval[])
{   
    int             len;
    int             base;
    int             i;
    unsigned int    dec_val;
     
    len = ft_strlen(hexval);
    base = 1;
    dec_val = 0;
    i = len;
    while (i-- >= 0)
    {
        if (hexval[i] >= '0' && hexval[i] <= '9')
            dec_val += (hexval[i] - 48)*base;
        else if (hexval[i] >= 'A' && hexval[i] <= 'F')
            dec_val += (hexval[i] - 55)*base;
        base *= 16;
    }
    return dec_val;
}