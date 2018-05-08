/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asn1converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 01:45:37 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/07 20:22:23 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_rsa.h"

static char         *ft_asnpad(char *hex_rep)
{
    char    first_byte[3];
    char    *tmp;

    if (strlen(hex_rep) % 2 != 0) {
        tmp = hex_rep;
        hex_rep = ft_strjoin("0", hex_rep);
        ft_strdel(&tmp);
    }
    ft_memcpy(first_byte, hex_rep, 2);
    first_byte[2]='\0';
    tmp = NULL;
    if (ft_hextodec(first_byte) > 0x7F)
    {
        tmp = hex_rep;
        hex_rep = ft_strjoin("00", hex_rep);
        ft_strdel(&tmp);
    }
    return (hex_rep);
}

static char         *ft_asnlen(char *hex_rep)
{
    int     len;
    int     threshold;
    char    *answer;
    int     prefix;

    len = ft_strlen(hex_rep) / 2;
    threshold = 0x7F;
// any length from 0 up to 0x7F is encoded as one byte in 00..7F;
// any higher length up to 0xFF is encoded as prefix 81 and one byte;
// any higher length up to 0xFFFF is encoded as prefix 82 and two bytes;
// any higher length up to 0xFFFFFF is encoded as prefix 83 and three bytes;
// any higher length up to 0xFFFFFFFF is encoded as prefix 84 and four bytes;
    if (len < threshold)
    {
        answer = ft_strnew(1);
        answer[0] = (char)len;
        return  (answer);
    }
    prefix = 0x81;
    while (true)
    {
        if (len <= threshold)
            break ;
        prefix++;
        threshold = threshold << 8 | 0xFF;
    }
    answer = ft_strnew(1 + (prefix - 0x80));
    answer[0] = (unsigned char)prefix;
    ft_memcpy(&answer[1], (char *)&len, len);
    return (answer);
}

static unsigned char   *ft_asnint(unsigned long number, int *size)
{
    char            *hex_rep;
    char            *encoded_len;
    unsigned char   *data;
    unsigned char   *answer;
    unsigned char   *tmp;

    hex_rep = ft_asnpad(ft_dectohex(number));
    encoded_len = ft_asnlen(hex_rep);
    *size = (2 + ft_strlen(hex_rep)/2 + ft_strlen(encoded_len)/2);
    answer = (unsigned char *)ft_strnew(*size);
    answer[0] = (char)INT_ASN1;
    tmp = answer;
    answer = (unsigned char *)ft_strjoin((char *)answer, encoded_len);
    ft_strdel((char **)&tmp);
    data = ft_hextodata(hex_rep);
    answer = ft_memjoin(answer, (1 + ft_strlen(encoded_len)), data,
                                            ft_strlen(hex_rep)/2);
    return (answer);
}

static unsigned char *ft_iterloop(t_dercrypto *main, unsigned char **asnencoded, int *total_size)
{
    t_itercrypto    iter;
    unsigned char   *tmp;
    unsigned char   *asnint;
    int             size;
    int             i;
    
    iter.dercrypto = *main;
    i = -1;
    size = 0;
    while (i++ < 8)
    {
        tmp = *asnencoded;
        asnint = ft_asnint(iter.itercrypto[i], &size);
        *asnencoded = ft_memjoin(*asnencoded, *total_size, asnint, size);
        *total_size += size;
        ft_strdel((char **)&tmp);
        ft_strdel((char **)&asnint);
    }
    return (*asnencoded);
}

unsigned char        *ft_get_asn1(t_dercrypto *main, int *total_size)
{
    unsigned char   *asnencoded;

    asnencoded = (unsigned char *)ft_strnew(*total_size);
    asnencoded[0] = (char)SEQUENCE_ASN1;
    asnencoded[1] = (char)INT_ASN1;
    asnencoded[2] = (char)0x01;
    asnencoded[3] = (char)0x00;
    asnencoded = ft_iterloop(main, &asnencoded, total_size);
    return (asnencoded);
}

