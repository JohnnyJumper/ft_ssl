/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:43:25 by jtahirov          #+#    #+#             */
/*   Updated: 2018/01/02 14:53:43 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/base64.h"

void			ft_base64(int argc, char **argv, bool cbc_mode)
{
	t_binput	*input;
	int			fd_input;
	int			fd_output;
	char		*res;

	fd_input = 0;
	fd_output = 1;
	if (cbc_mode)
		;
	input = create_struct();
	ft_parse_base64_flags(input, argc, argv);
	if (input->flag.input)
		fd_input = ft_openfile(input->input_filename, true);
	if (input->flag.output)
		fd_output = ft_openfile(input->output_filename, false);
	res = (input->flag.decode) ? ft_base64_hdecode(fd_input, input) :
								ft_base64_hencode(fd_input, input);
	ft_printf("%r %s", fd_output, res);
}
