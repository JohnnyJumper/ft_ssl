/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:18:10 by jtahirov          #+#    #+#             */
/*   Updated: 2017/11/21 19:56:14 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_sint(t_arg *args, va_list *ap)
{
	if (args->length[0] == '\0')
		args->val.sint = va_arg(*ap, int);
	else if (args->length[0] == 'h' && args->length[1] == 'h')
		args->val.sint = (char)va_arg(*ap, int);
	else if (args->length[0] == 'h')
		args->val.sint = (short int)va_arg(*ap, int);
	else if (args->length[0] == 'l' && args->length[1] == 'l')
		args->val.sint = va_arg(*ap, long long int);
	else if (args->length[0] == 'l')
		args->val.sint = va_arg(*ap, long int);
	else if (args->length[0] == 'j')
		args->val.sint = va_arg(*ap, intmax_t);
	else if (args->length[0] == 'z')
		args->val.sint = va_arg(*ap, size_t);
}

void	conversion_uint(t_arg *args, va_list *ap)
{
	if (args->sp == 'U')
		args->val.uint = va_arg(*ap, unsigned long int);
	else if (args->length[0] == '\0')
		args->val.uint = va_arg(*ap, unsigned int);
	else if (args->length[0] == 'h' && args->length[1] == 'h')
		args->val.uint = (unsigned char)va_arg(*ap, unsigned int);
	else if (args->length[0] == 'h')
		args->val.uint = (unsigned short)va_arg(*ap, unsigned int);
	else if (args->length[0] == 'l' && args->length[1] == 'l')
		args->val.uint = va_arg(*ap, unsigned long long int);
	else if (args->length[0] == 'l')
		args->val.uint = va_arg(*ap, unsigned long int);
	else if (args->length[0] == 'j')
		args->val.uint = va_arg(*ap, uintmax_t);
	else if (args->length[0] == 'z')
		args->val.uint = va_arg(*ap, size_t);
}
